#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

int n, m, k;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };


int main() {
	cin >> n >> m >> k;

	vector< vector<int> > arr(n, vector<int>(m, 0));

	// 하나의 위치(i,j)에 대해서 벽을 0번, 1번, 2번,,,k번째 부수고 지나갈 때 각각 값이 다르다.
	// 따라서 각 좌표에 대해서 k번의 경우의 수를 생각해야하기 때문에 삼차원 배열 선언
	int dist[1001][1001][11];

	string temp = "";
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}


	dist[0][0][0] = 1;
	queue< tuple<int, int, int> > Q;
	Q.push(make_tuple(0, 0, 0));

	int y, x, kk, ny, nx;
	while (!Q.empty()) {
		tie(y, x, kk) = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];

			if (ny < 0 || nx < 0 || nx >= m || ny >= n) continue;

			// ny, nx 위치에 벽이 있고, 벽을 부술 기회가 남았으며, (ny,nx)의 벽을 kk+1번째로 부쉈던 적 없는 경우
			if (arr[ny][nx] == 1 && kk + 1 <= k && dist[ny][nx][kk + 1] == 0) {
				dist[ny][nx][kk + 1] = dist[y][x][kk] + 1;
				Q.push(make_tuple(ny, nx, kk + 1));
			}

			// ny, nx 위치가 빈 칸인이고 한번도 방문하지 않았던 경우
			if (arr[ny][nx] == 0 && dist[ny][nx][kk] == 0) {
				dist[ny][nx][kk] = dist[y][x][kk] + 1;
				Q.push(make_tuple(ny, nx, kk));
			}

		}
	}

	int ans = -1;

	// 도착점 (n-1, m-1)위치에 대해서 방문을 0 ~ k 번 부신 모든 경우의 수 확인
	for (int i = 0; i <= k; i++) {
		if (dist[n - 1][m - 1][i] == 0) continue;
		if (ans == -1 || ans > dist[n - 1][m - 1][i]) ans = dist[n - 1][m - 1][i];
	}
	cout << ans << endl;
}
