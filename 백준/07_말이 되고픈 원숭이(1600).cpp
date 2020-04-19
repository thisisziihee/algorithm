#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int kx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int ky[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int arr[210][210];
int dist[210][210][40];

int main() {
	int k, h, w;
	cin >> k >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dist, -1, sizeof(dist));

	queue< tuple<int, int, int> > Q;
	Q.push(make_tuple(0, 0, 0));
	dist[0][0][0] = 0;

	int x, y, kk, ny, nx;
	while (!Q.empty()) {
		tie(y, x, kk) = Q.front();
		Q.pop();

		// (y, x) 위치를 기준으로 상하좌우 확인
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];	
			if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
			if (arr[ny][nx] == 1) continue;
			if (dist[ny][nx][kk] != -1) continue;

			dist[ny][nx][kk] = dist[y][x][kk] + 1;
			Q.push(make_tuple(ny, nx, kk));
		
		}

		// (y, x) 위치를 기준으로 말의 움직임 8개의 위치 확인
		for (int i = 0; i < 8; i++) {
			ny = y + ky[i];
			nx = x + kx[i];

			if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
			if (arr[ny][nx] == 1) continue;
			if (kk + 1 > k) continue;
			if (dist[ny][nx][kk + 1] != -1) continue;

			dist[ny][nx][kk + 1] = dist[y][x][kk] + 1;
			Q.push(make_tuple(ny, nx, kk + 1));
		}
	}

	int ans = -1;
	for (int i = 0; i <= k; i++) {
		if (dist[h - 1][w - 1][i] == -1) continue;
		if (ans == -1 || ans > dist[h - 1][w - 1][i]) ans = dist[h - 1][w - 1][i];
	}
	cout << ans << endl;
	return 0;
}