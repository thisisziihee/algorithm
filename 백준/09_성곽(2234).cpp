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

	cout << *max_element(rooms.begin(), rooms.end()) << endl;

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = j;
			int y = i;
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				if (group[y][x] == group[ny][nx]) continue;

				if (arr[y][x] & (1 << k)) {
					if (ans == -1 || rooms[group[y][x]] + rooms[group[ny][nx]] > ans) {
						ans = rooms[group[y][x]] + rooms[group[ny][nx]];
					}
				}
			}
		}
	}
	cout << ans << endl;
}