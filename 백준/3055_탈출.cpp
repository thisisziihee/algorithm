#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int sx, sy, gx, gy;
int n, m;
string arr[50];
queue< pair<int, int> > Q;

int dist_water[50][50];
int dist_hh[50][50];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };



int main() {
	cin >> n >> m;

	memset(dist_water, -1, sizeof(dist_water));
	memset(dist_hh, -1, sizeof(dist_hh));

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '*') {
				Q.push(make_pair(i, j));
				dist_water[i][j] = 0;
			}
			if (arr[i][j] == 'S') {
				sx = j; sy = i;
				arr[i][j] = '.';
				dist_hh[i][j] = 0;
			}
			if (arr[i][j] == 'D') {
				gx = j; gy = i;
			}
		}
	}
	
	int x, y, ny, nx;
	
	// dist_water �迭���� i, jĭ�� ���� ���� �ð�(��)�� ǥ��
	while (!Q.empty()) {
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (dist_water[ny][nx] != -1) continue;
			if (arr[ny][nx] != '.') continue;

			dist_water[ny][nx] = dist_water[y][x] + 1;
			Q.push(make_pair(ny, nx));
		}
	}


	// dist_hh �迭���� (sy, sx) ��ġ�� �������� �� �и��� ����ġ�� ��θ� ����
	// ���� (ny, nx)��ǥ�� �̵��� ������ dist_water[ny][nx] ���� ���ؾ��Ѵ�.
	Q.push(make_pair(sy, sx));
	while (!Q.empty()) {
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || nx < 0 || nx >= m || ny >= n) continue;
			if (dist_hh[ny][nx] != -1) continue;
			if (arr[ny][nx] == 'X' || arr[ny][nx] == '*') continue;

			// ����ġ�� [ny][nx] ��ġ�� �̵��ϱ� ���̳� ���ÿ� ���� ������ ���
			if (dist_water[ny][nx] != -1 && dist_hh[y][x] + 1 >= dist_water[ny][nx]) continue;


			dist_hh[ny][nx] = dist_hh[y][x] + 1;
			Q.push(make_pair(ny, nx));
		}
	}

	if (dist_hh[gy][gx] == -1) cout << "KAKTUS" << endl;
	else cout << dist_hh[gy][gx] << endl;
}