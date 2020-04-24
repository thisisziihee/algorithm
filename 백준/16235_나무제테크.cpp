#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int n, m, kk;
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int arr[10][10];
int add[10][10];

queue<int> dead_tree[10][10];
deque<int> tree[10][10];

int main() {
	cin >> n >> m >> kk;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> add[i][j];
			arr[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> y >> x >> z;
		tree[y - 1][x - 1].push_back(z);
	}

	for (int year = 1; year <= kk; year++) {
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int len = tree[i][j].size();
				for (int k = 0; k < len; k++) {

					int val = tree[i][j].front();
					tree[i][j].pop_front();

					if (arr[i][j] >= val) {
						arr[i][j] -= val;
						tree[i][j].push_back(val + 1);
					}
					else {
						dead_tree[i][j].push(val);
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				while (!dead_tree[i][j].empty()) {
					int val = dead_tree[i][j].front();
					dead_tree[i][j].pop();
					arr[i][j] += (val / 2);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (tree[i][j].size() == 0) continue;

				int len = tree[i][j].size();

				for (int k = 0; k < len; k++) {
					if (tree[i][j][k] % 5 == 0) {
						for (int dir = 0; dir < 8; dir++) {
							int ny = i + dy[dir];
							int nx = j + dx[dir];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
							tree[ny][nx].push_front(1);
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] += add[i][j];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans << endl;
}