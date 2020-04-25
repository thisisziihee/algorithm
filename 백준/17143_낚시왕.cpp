#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shark {
	int y, x, speed, dir, size, idx;
};

vector<int> arr[101][101];
vector<Shark> S;

int n, m, shark_cnt;
int ans = 0;
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, -1, 1, 0, 0 };

bool whoIsBigger(int a, int b) {
	if (S[a].size > S[b].size) return true;
	return false;
}

// 현재 낚시왕이 있는 열(x)에서 가장 가까운 상어 캐치
void catch_shark(int x) {
	for (int y = 0; y < n; y++) {
		if (arr[y][x].size() != 0) {
			// ans에 상어 size 더해주고, size를 0으로 바꿔 없는 상어 처리
			int idx = arr[y][x].front();
			ans += S[idx].size;
			S[idx].size = 0;
			arr[y][x].clear();
			break;
		}
	}
}

void move_shark() {
	// 1. 기존의 arr에서 상어 정보 삭제. 
	// 어차피 S 벡터에 저장되어 있으므로 괜찮. 한 칸에 한 마리만 들어갈 수 있도록 하기 위함
	for (int i = 0; i < S.size(); i++) {
		if (S[i].size == 0) continue;
		int y = S[i].y;
		int x = S[i].x;
		arr[y][x].clear();
	}

	// 2. 상어 이동
	// 상어의 speed 즉, 이동 횟수가 1000번이 되면 시간초과
	// 상하로 움직이는 경우, 상어가 다시 제자리로 돌아오려면 (n-1)*2 만큼 이동. 좌우로 움직이는 경우, (m-1)*2
	// 이동횟수를 (제자리 이동 횟수)로 나눈 나머지만큼만 이동하여 시간 초과 방지
	int y, x, d, s, ny, nx;
	for (int i = 0; i < S.size(); i++) {
		if (S[i].size == 0) continue;

		y = S[i].y;
		x = S[i].x;
		d = S[i].dir;
		s = S[i].speed;

		if (d == 1 || d == 2) {
			int step = s % ((n - 1) * 2);
			int step_cnt = 0;
			while (step_cnt < step) {
				ny = y + dy[d];
				nx = x + dx[d];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
					if (d == 1) d = 2;
					else d = 1;
				}
				else {
					y = ny; x = nx;
					step_cnt += 1;
				}
			}

		}
		else {
			int step = s % ((m - 1) * 2);
			int step_cnt = 0;
			while (step_cnt < step) {
				ny = y + dy[d];
				nx = x + dx[d];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
					if (d == 3) d = 4;
					else d = 3;
				}
				else {
					y = ny; x = nx;
					step_cnt += 1;
				}
			}
		}

		S[i].y = y;
		S[i].x = x;
		S[i].dir = d;
		arr[y][x].push_back(i);
	}
}

// 한 칸에 두 마리 이상의 상어 있을 경우, 제일 큰 상어만 저장
void kill_shark() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j].size() > 1) {
				// 1. whoIsBigger 함수로 상어의 크기를 내림차순으로 정렬
				sort(arr[i][j].begin(), arr[i][j].end(), whoIsBigger);

				// 2. 가장 사이즈가 큰 상어의 인덱스 번호 저장
				int survived_shark = arr[i][j][0];

				// 3. 나머지 상어들 없애기
				for (int k = 1; k < arr[i][j].size(); k++) {
					S[arr[i][j][k]].size = 0;
					S[arr[i][j][k]].y = -1;
					S[arr[i][j][k]].x = -1;
				}

				// 4. 기존의 arr[i][j] 정리하고, 새로 push_back
				arr[i][j].clear();
				arr[i][j].push_back(S[survived_shark].idx);
			}
		}
	}
}


int main() {
	cin >> n >> m >> shark_cnt;
	int a, b, c, d, e;

	for (int i = 0; i < shark_cnt; i++) {
		cin >> a >> b >> c >> d >> e;
		arr[a - 1][b - 1].push_back(i);
		S.push_back({ a - 1, b - 1, c, d, e, i });
	}

	int fisherman = -1;

	while (fisherman < m && shark_cnt != 0) {

		// 1. 낚시왕이 오른쪽으로 한 칸 이동
		fisherman += 1;

		// 2. 낚시왕이 서 있는 열에서 가장 가까운 상어 잡기
		catch_shark(fisherman);

		// 3. 상어 이동
		move_shark();

		// 4. 이동한 상어들이 한 칸에 여러 마리 있는 경우 확인
		kill_shark();
	}
	cout << ans << endl;
}