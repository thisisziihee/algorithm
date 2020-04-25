// 1 : 20 ���� ~ 2 : 57 ��

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

		// 1. �̼������� Ȯ��
		// - ��� ĭ�� ���ÿ� ����. 
		// - ������ ����ų� ����û���Ⱑ �ִ� ĭ�� �ƴϰ��� ��� Ȯ�� ��
		// - ������ �� �������� Ȯ��� �� ĭ�� 1/5 ���� Ȯ��ǰ� ������ŭ ���� ĭ�� �̼��������� ���ҵ�
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


		// 2. ����û���� �۵�
		// - ����û���⸦ �������� �������δ� �ݽð���� ��ȯ. �Ʒ������δ� �ð���� ��ȯ
		// - �ٶ��� ������ �̼��������� �� ĭ�� �̵�
		// - ����û����� �� �̼��������� �����

		// 2-1. ����û���� ��ܺ� (y1, 0) �������� �ݽð� ����
		arr[y1 - 1][0] = 0;
		for (int y = y1 - 1; y > 0; y--) arr[y][0] = arr[y - 1][0];
		for (int x = 0; x < m - 1; x++) arr[0][x] = arr[0][x + 1];
		for (int y = 0; y < y1; y++) arr[y][m - 1] = arr[y + 1][m - 1];
		for (int x = m - 1; x > 1; x--) arr[y1][x] = arr[y1][x - 1];
		arr[y1][1] = 0;

		// 2-2. ����û���� �ϴܺ� (y2, 0) �������� �ð� ����
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