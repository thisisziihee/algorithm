#include<bits/stdc++.h>
using namespace std;

int r, c;
char arr[101][101];
bool visited[101][101];
vector< pair<int, int> > group;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int y, int x) {
	if (arr[y][x] == '.') return;
	if (visited[y][x]) return;

	visited[y][x] = true;
	group.push_back(make_pair(y, x));
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (xx >= 0 && yy >= 0 && xx < c &&yy < r) {
			if (arr[yy][xx] == 'x' && !visited[yy][xx]) {
				dfs(yy, xx);
			}
		}
	}
}

void simulate() {
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '.') continue;
			if (visited[i][j]) continue;

			// 1. �ϳ��� Ŭ�����͸� �̷�� �̳׶��� ��ġ ����
			group.clear();
			dfs(i, j);

			// 2. group�� ����� �̳׶� ��ǥ���� �� x��ǥ�� ���� ���� y��ǥ�� ���� �� ���ϱ�
			vector<int> col_each_row(c, -1);
			for (auto &p : group) {
				col_each_row[p.second] = max(col_each_row[p.second], p.first);
				arr[p.first][p.second] = '.';
			}

			// 3. group �̳׶� ��ǥ�κ��� �� ĭ ������ ������ Ȯ��
			// �ٸ� �̳׶��� �ε����� �ʾƾ��ϸ�, ��ĭ�� �����ؾ���
			int y = 0;
			int lowest_gap = r;
			for (int k = 0; k < c; k++) {
				if (col_each_row[k] == -1) continue;
				for (y = col_each_row[k]; y < r && arr[y][k] == '.'; y++);
				lowest_gap = min(lowest_gap, y - col_each_row[k] - 1);
			}

			// 4. (3)���� lowest_gap��ŭ group�� �ִ� �̳׶� ��ǥ �ű��
			for (auto &p : group) {
				p.first += lowest_gap;
				arr[p.first][p.second] = 'x';
				visited[p.first][p.second] = true;
			}
		}
	}
}

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
	}

	int n, height;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> height;
		height = r - height;
		if (i % 2 == 0) {
			for (int j = 0; j < c; j++) {
				if (arr[height][j] == 'x') {
					arr[height][j] = '.';
					break;
				}
			}
		}
		else {
			for (int j = c - 1; j >= 0; j--) {
				if (arr[height][j] == 'x') {
					arr[height][j] = '.';
					break;
				}
			}
		}

		simulate();
	}
	print();
}