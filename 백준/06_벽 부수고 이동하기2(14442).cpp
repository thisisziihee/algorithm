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

	// �ϳ��� ��ġ(i,j)�� ���ؼ� ���� 0��, 1��, 2��,,,k��° �μ��� ������ �� ���� ���� �ٸ���.
	// ���� �� ��ǥ�� ���ؼ� k���� ����� ���� �����ؾ��ϱ� ������ ������ �迭 ����
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

			// ny, nx ��ġ�� ���� �ְ�, ���� �μ� ��ȸ�� ��������, (ny,nx)�� ���� kk+1��°�� �ν��� �� ���� ���
			if (arr[ny][nx] == 1 && kk + 1 <= k && dist[ny][nx][kk + 1] == 0) {
				dist[ny][nx][kk + 1] = dist[y][x][kk] + 1;
				Q.push(make_tuple(ny, nx, kk + 1));
			}

			// ny, nx ��ġ�� �� ĭ���̰� �ѹ��� �湮���� �ʾҴ� ���
			if (arr[ny][nx] == 0 && dist[ny][nx][kk] == 0) {
				dist[ny][nx][kk] = dist[y][x][kk] + 1;
				Q.push(make_tuple(ny, nx, kk));
			}

		}
	}

	int ans = -1;

	// ������ (n-1, m-1)��ġ�� ���ؼ� �湮�� 0 ~ k �� �ν� ��� ����� �� Ȯ��
	for (int i = 0; i <= k; i++) {
		if (dist[n - 1][m - 1][i] == 0) continue;
		if (ans == -1 || ans > dist[n - 1][m - 1][i]) ans = dist[n - 1][m - 1][i];
	}
	cout << ans << endl;
}
