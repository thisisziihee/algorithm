#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int arr[50][50];
int group[50][50];
vector<int> rooms;

int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int bfs(int i, int j, int cnt) {
	queue< pair<int, int> > Q;
	Q.push(make_pair(i, j));

	group[i][j] = cnt;
	
	int room_cnt = 0;
	int x, y, nx, ny;
	
	while (!Q.empty()) {
		x = Q.front().second;
		y = Q.front().first;
		Q.pop();
		room_cnt += 1;

		for (int k = 0; k < 4; k++) {
			ny = y + dy[k];
			nx = x + dx[k];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (group[ny][nx] != 0) continue;

			// (y, x) 좌표에서 k번째 방향에 (ny, nx) 있음
			// arr[y][x] 값이 2진수 비트로 나오기 때문에 1을 k만큼 shift 연산시킨 값과 arr[y][x]값을 & 처리하여
			// (y, x)좌표와 (ny, nx) 사이에 벽이 있는지 확인
			if (arr[y][x] & (1 << k)) continue;

			group[ny][nx] = cnt;
			Q.push(make_pair(ny, nx));
		}
	}
	return room_cnt;
}


int main() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	memset(group, 0, sizeof(group));
	rooms.push_back(0);

	// 1. arr배열에서 벽을 기준으로 몇 개의 방으로 나눠지는지, 각 방의 넓이 확인
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (group[i][j] == 0) {
				cnt += 1;
				rooms.push_back(bfs(i, j, cnt));
			}
		}
	}
	cout << cnt << endl;

	// 2. 가장 넒은 방 출력
	cout << *max_element(rooms.begin(), rooms.end()) << endl;


	// 3. 벽 하나를 제거한다면 얻을 수 있는 방의 넓이
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = j;
			int y = i;
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

				// (y, x) 칸과 (ny, nx)칸은 서로 다른 방이어야 한다.
				if (group[y][x] == group[ny][nx]) continue;

				// 두 좌표가 서로 다른 방이고, 두 칸 사이에 제거할 벽이 있는 경우
				if (arr[y][x] & (1 << k)) {
					// 두 방의 넓이 최댓값 갱신
					if (ans == -1 || rooms[group[y][x]] + rooms[group[ny][nx]] > ans) {
						ans = rooms[group[y][x]] + rooms[group[ny][nx]];
					}
				}
			}
		}
	}
	cout << ans << endl;
}