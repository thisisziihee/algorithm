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

// ���� ���ÿ��� �ִ� ��(x)���� ���� ����� ��� ĳġ
void catch_shark(int x) {
	for (int y = 0; y < n; y++) {
		if (arr[y][x].size() != 0) {
			// ans�� ��� size �����ְ�, size�� 0���� �ٲ� ���� ��� ó��
			int idx = arr[y][x].front();
			ans += S[idx].size;
			S[idx].size = 0;
			arr[y][x].clear();
			break;
		}
	}
}

void move_shark() {
	// 1. ������ arr���� ��� ���� ����. 
	// ������ S ���Ϳ� ����Ǿ� �����Ƿ� ����. �� ĭ�� �� ������ �� �� �ֵ��� �ϱ� ����
	for (int i = 0; i < S.size(); i++) {
		if (S[i].size == 0) continue;
		int y = S[i].y;
		int x = S[i].x;
		arr[y][x].clear();
	}

	// 2. ��� �̵�
	// ����� speed ��, �̵� Ƚ���� 1000���� �Ǹ� �ð��ʰ�
	// ���Ϸ� �����̴� ���, �� �ٽ� ���ڸ��� ���ƿ����� (n-1)*2 ��ŭ �̵�. �¿�� �����̴� ���, (m-1)*2
	// �̵�Ƚ���� (���ڸ� �̵� Ƚ��)�� ���� ��������ŭ�� �̵��Ͽ� �ð� �ʰ� ����
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

// �� ĭ�� �� ���� �̻��� ��� ���� ���, ���� ū �� ����
void kill_shark() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j].size() > 1) {
				// 1. whoIsBigger �Լ��� ����� ũ�⸦ ������������ ����
				sort(arr[i][j].begin(), arr[i][j].end(), whoIsBigger);

				// 2. ���� ����� ū ����� �ε��� ��ȣ ����
				int survived_shark = arr[i][j][0];

				// 3. ������ ���� ���ֱ�
				for (int k = 1; k < arr[i][j].size(); k++) {
					S[arr[i][j][k]].size = 0;
					S[arr[i][j][k]].y = -1;
					S[arr[i][j][k]].x = -1;
				}

				// 4. ������ arr[i][j] �����ϰ�, ���� push_back
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

		// 1. ���ÿ��� ���������� �� ĭ �̵�
		fisherman += 1;

		// 2. ���ÿ��� �� �ִ� ������ ���� ����� ��� ���
		catch_shark(fisherman);

		// 3. ��� �̵�
		move_shark();

		// 4. �̵��� ������ �� ĭ�� ���� ���� �ִ� ��� Ȯ��
		kill_shark();
	}
	cout << ans << endl;
}