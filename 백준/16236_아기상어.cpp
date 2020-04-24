#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[20][20];
bool visited[20][20];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

// 아기상어의 현재 위치, 크기, 지금까지 먹은 물고기 수 저장
struct Shark {
	int y, x, size, ate;
	void sizeUp() {
		ate = 0;
		size += 1;
	}
};

// 아기상어가 움직이려는 좌표에 대한 정보
// Q에 넣고 움직인 칸의 수가 가장 적은 것부터 추출됨
struct State {
	int y, x, dis;
	
	State(int a, int b, int c) {
		y = a; x = b; dis = c;
	}

	bool operator<( const State &bb) const{
		if (dis == bb.dis) {
			if (y == bb.y) return x > bb.x;
			else return y > bb.y;
		}
		else return dis > bb.dis;
	}
};

int main() {
	cin >> n;
	
	Shark S;
	priority_queue<State> Q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				S.y = i; S.x = j; S.size = 2; S.ate = 0;
				arr[i][j] = 0;
			}
		}
	}

	Q.push(State(S.y, S.x, 0));
	int y, x, dis;
	int ans = 0;

	while (!Q.empty()) {

		State temp = Q.top();
		Q.pop();

		// 이동하려는 위치
		y = temp.y;
		x = temp.x;
		dis = temp.dis;

		// 아기상어가 이동한 (y, x) 좌표에 물고기가 있으며, 아기상어보다 작아서 먹을 수 있는 경우
		if (arr[y][x] != 0 && arr[y][x] < S.size) {
			
			// 1. 아기 상어를 물고기가 있는 (y,x) 위치로 옮기고 물고기 먹음
			S.ate += 1;
			S.y = y;
			S.x = x;
			
			// 2. 해당 물고기를 먹고나서, 사이즈업할 수 있는지 확인
			if (S.ate == S.size) S.sizeUp();

			// 3. 물고기 먹은 자리 비워주기
			arr[y][x] = 0;

			// 4. 다시 현재 아기상어의 위치 (y, x)에서 다음 위치를 탐색해야하므로 visited 배열 초기화
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					visited[i][j] = false;
				}
			}

			// 5. Q에 들어있는 좌표 삭제
			// 현재 Q에는 이전의 아기 상어 위치(pre_y, pre_x)에서 이동할 수 있는 좌표들만 있음
			// 그러나 지금 (y, x)위치로 이동했기 때문에, 기존에 Q에 있던 좌표들 무의미하므로 Q 비워줌
			while (!Q.empty()) Q.pop();

			// 6. (original_y, original_x) -> (y, x) 이동하기 까지 거친 칸의 개수 갱신
			// 초기의 아기상어 위치부터 현재 아기상어 위치로 이동하기까지 몇개의 칸을 거쳤는지
			ans = dis;
		}

		// (y, x)에서 다음으로 이동할 위치 탐색
		// 1. 현재 위치 (y, x)에 물고기가 있고 그것을 먹은 경우
		// 2. 물고기는 먹지 못하고 지나가기만 한 경우
		// 현재 위치 (y, x)에서 상하좌우 인접한 칸중에 지나갈 수 있는 위치 탐색
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[ny][nx] > S.size) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = true;
			Q.push(State(ny, nx, dis + 1));
		}
	}
	cout << ans << endl;
}