// 1 : 20 시작 ~ 2 : 57 끝

#include <iostream>
#include <queue>

using namespace std;

int n, m, sec;
int arr[50][50];
int copied_arr[50][50];

queue< pair<int, int> > Q;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	cin >> n >> m >> sec;
	int y1 = -1, y2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (y1 == -1)  y1 = i;
				else  y2 = i;
			}
		}
	}


	for (int time = 1; time <= sec; time++) {

		// 1. 미세먼지의 확산
		// - 모든 칸이 동시에 진행. 
		// - 범위를 벗어나거나 공기청정기가 있는 칸이 아니고서야 모두 확산 됨
		// - 인접한 네 방향으로 확산됨 한 칸의 1/5 양이 확산되고 나간만큼 현재 칸의 미세먼지양이 감소됨
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && arr[i][j] != -1) {
					Q.push(make_pair(i, j));
				}
				copied_arr[i][j] = arr[i][j];
			}
		}

		while(!Q.empty()){
			int y = Q.front().first;
			int x = Q.front().second;
			Q.pop();

			int dust_cnt = 0;
			int dust = copied_arr[y][x] / 5;

			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if (copied_arr[ny][nx] == -1) continue;

				arr[ny][nx] += dust;
				dust_cnt += 1;
			}
			arr[y][x] -= (dust * dust_cnt);
		}


		// 2. 공기청정기 작동
		// - 공기청정기를 기준으로 윗쪽으로는 반시계방향 순환. 아래쪽으로는 시계방향 순환
		// - 바람의 방향대로 미세먼지들이 한 칸씩 이동
		// - 공기청정기로 들어간 미세먼지들은 사라짐

		// 2-1. 공기청정기 상단부 (y1, 0) 기준으로 반시계 방향
		arr[y1 - 1][0] = 0;
		for (int y = y1 - 1; y > 0; y--) arr[y][0] = arr[y - 1][0];
		for (int x = 0; x < m - 1; x++) arr[0][x] = arr[0][x + 1];
		for (int y = 0; y < y1; y++) arr[y][m - 1] = arr[y + 1][m - 1];
		for (int x = m - 1; x > 1; x--) arr[y1][x] = arr[y1][x - 1];
		arr[y1][1] = 0;

		// 2-2. 공기청정기 하단부 (y2, 0) 기준으로 시계 방향
		arr[y2 + 1][0] = 0;
		for (int y = y2 + 1; y < n - 1; y++) arr[y][0] = arr[y + 1][0];
		for (int x = 0; x < m - 1; x++) arr[n - 1][x] = arr[n - 1][x + 1];
		for (int y = n - 1; y > y2; y--) arr[y][m - 1] = arr[y - 1][m - 1];
		for (int x = m - 1; x > 1; x--) arr[y2][x] = arr[y2][x - 1];
		arr[y2][1] = 0;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == -1 || arr[i][j] == 0) continue;
			ans += arr[i][j];
		}
	}
	cout << ans << endl;
}