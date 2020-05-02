#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

/*
1. 하나의 뿌요를 기준으로 상하좌우 4개 이상의 같은 색 있으면 한꺼번에 없어짐
2. 없어지고 나면 위에 있는 다른 뿌요들이 내려옴
3. 1-2 과정이 한 번 반복할 때마다 1연쇄씩 늘어남
4. 터질 수 있는 뿌요가 여러그룹잉라면 동시에 터져야함
5. 여러 그룹이 터지더라도 한 번의 연쇄 추가

. 빈공간  R 빨강. G 초록. B 파랑 . P 보라. Y 노랑

입력으로 들어온 뿌요에서 몇 연쇄가 되는지 출력
*/

char arr[12][6];
bool visited[12][6] = { false };
vector< pair<int, int> > group[20];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// 1. 같은 색깔을 가져야한다. 
// 2. 4개 이상이어야함
bool check_puyo(int i, int j, int idx) {
	queue< pair<int, int> > Q;

	Q.push(make_pair(i, j));
	group[idx].push_back(make_pair(i, j));
	visited[i][j] = true;

	int x, y, nx, ny;
	int puyo_cnt = 1;

	while (!Q.empty()) {
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();
		for (int k = 0; k < 4; k++) {
			ny = y + dy[k];
			nx = x + dx[k];
			
			if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12) continue;
			if (visited[ny][nx]) continue;
			if (arr[ny][nx] != arr[i][j]) continue;

			visited[ny][nx] = true;
			Q.push(make_pair(ny, nx));
			group[idx].push_back(make_pair(ny, nx));
			puyo_cnt += 1;
		}
	}

	if (puyo_cnt < 4) {
		for (int k = 0; k < group[idx].size(); k++) {
			y = group[idx][k].first;
			x = group[idx][k].second;
			visited[y][x] = false;
		}
		group[idx].clear();
		return false;
	}
	return true;
}


void drag_puyo_down(int x) {
	for (int i = 11; i > 0; i--) {
		if (arr[i][x] == '.' && i > 0) {
			int y = i - 1;
			while (y >= 0) {
				if (arr[y][x] != '.') {
					arr[i][x] = arr[y][x];
					arr[y][x] = '.';
					break;
				}
				y -= 1;
			}
		}
	}
}

int main() {
	int ans = 0;

	// 1. 상대방의 뿌요 주어짐
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}

	// 2. 더 이상 터질 뿌요가 없을 때 까지 진행 
	while(true) {

		// (1) 현재 상황에서 터질 뿌요 확인 (여러 그룹)
		for (int i = 0; i < 20; i++) {
			group[i].clear();
		}
		memset(visited, false, sizeof(visited));

		int idx = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (visited[i][j] || arr[i][j] == '.') continue;
				if (check_puyo(i, j, idx)) idx += 1;
			}
		}

		// (2) 더 이상 터질 뿌요 없으면 while문 탈출
		if (idx == 0) break;


		// (3) 해당되는 뿌요 없애기
		for (int i = 0; i < 20; i++) {
			if (group[i].size() == 0) continue;
			else {
				for (int k = 0; k < group[i].size(); k++) {
					int y = group[i][k].first;
					int x = group[i][k].second;
					arr[y][x] = '.';
				}
			}
		}

		// (4) 위에 있는 뿌요들 내리기
		for (int x = 0; x < 6; x++) {
			drag_puyo_down(x);
		}

		// (5) 1연쇄 추가
		ans += 1;
	}

	// 3. 상대방의 뿌요에 대한 연쇄값 출력
	cout << ans << endl;
	
}