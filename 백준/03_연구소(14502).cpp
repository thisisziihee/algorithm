#include<bits/stdc++.h>
using namespace std;

int n, m;
int ori_arr[8][8];
int temp[8][8];
int visited[8][8];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };


void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (xx >= 0 && yy >= 0 && xx < m && yy < n) {
			if (temp[yy][xx] == 0 && !visited[yy][xx]) {
				temp[yy][xx] = 2;
				dfs(yy, xx);
			}
		}
	}
}

int count_safety_zone() {
	// 1. 벽 3개 세운 연구실 복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = ori_arr[i][j];
		}
	}

	// 2. 연구실 바이러스 퍼지기
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 2 && visited[i][j] == 0) {
				dfs(i, j);
			}
		}
	}
	
	// 3. 바이러스가 닿지 않는 부분 체크
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) cnt += 1;
		}
	}
	return cnt;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ori_arr[i][j];
		}
	}

	int ans = 0;
	for (int y1 = 0; y1 < n; y1++) {
		for (int x1 = 0; x1 < m; x1++) {
			if (ori_arr[y1][x1] != 0) continue;
			for (int y2 = 0; y2 < n; y2++) {
				for (int x2 = 0; x2 < m; x2++) {
					if (ori_arr[y2][x2] != 0) continue;
					for (int y3 = 0; y3 < n; y3++) {
						for (int x3 = 0; x3 < m; x3++) {
							if (ori_arr[y3][x3] != 0) continue;

							if (y1 == y2 && x1 == x2) continue;
							if (y2 == y3 && x2 == x3) continue;
							if (y1 == y3 && x1 == x3) continue;

							ori_arr[y1][x1] = 1;
							ori_arr[y2][x2] = 1;
							ori_arr[y3][x3] = 1;
							
							int temp_ans = count_safety_zone();
							ans = max(ans, temp_ans);

							ori_arr[y1][x1] = 0;
							ori_arr[y2][x2] = 0;
							ori_arr[y3][x3] = 0;
						}
					}
				}
			}
		}
	}

	cout << ans << endl;
}