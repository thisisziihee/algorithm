#include<bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = 2147000000;

void check(int y, int x, int dir, vector< vector<int> > &a, vector< vector<int> >&b) {
	int i = y, j = x;
	while (i >= 0 && j >= 0 && i < n && j < m) {
		if (a[i][j] == 6) break;
		b[i][j] = a[y][x];
		i += dy[dir];
		j += dx[dir];
	}
}


void solution(int index, vector< vector<int> > &arr, vector< tuple<int, int, int> > &cctv, vector<int> dirs) {
	if (index == cctv.size()) {
		vector< vector<int> > arr2(arr);
		for (int i = 0; i < cctv.size(); i++) {
			int what, y, x;
			tie(what, y, x) = cctv[i];
			if (what == 1) {
				check(y, x, dirs[i], arr, arr2);
			}
			else if (what == 2) {
				check(y, x, dirs[i], arr, arr2);
				check(y, x, (dirs[i] + 2) % 4, arr, arr2);
			}
			else if (what == 3) {
				check(y, x, dirs[i], arr, arr2);
				check(y, x, (dirs[i] + 1) % 4, arr, arr2);
			}
			else if (what == 4) {
				check(y, x, dirs[i], arr, arr2);
				check(y, x, (dirs[i] + 1) % 4, arr, arr2);
				check(y, x, (dirs[i] + 2) % 4, arr, arr2);
			}
			else if (what == 5) {
				check(y, x, dirs[i], arr, arr2);
				check(y, x, (dirs[i] + 1) % 4, arr, arr2);
				check(y, x, (dirs[i] + 2) % 4, arr, arr2);
				check(y, x, (dirs[i] + 3) % 4, arr, arr2);
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr2[i][j] == 0) {
					cnt += 1;
				}
			}
		}
		ans = min(ans, cnt);
	}
	else {
		for (int i = 0; i < 4; i++) {
			dirs[index] = i;
			solution(index + 1, arr, cctv, dirs);
		}
	}
}


int main() {
	cin >> n >> m;

	vector< vector<int> > arr(n, vector<int>(m, 0));
	vector< tuple<int, int, int> > cctv;
	vector<int> dirs;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				cctv.emplace_back(arr[i][j], i, j);
				dirs.push_back(0);
			}
		}
	}

	solution(0, arr, cctv, dirs);
	cout << ans << endl;
}