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

			// 1. 하나의 클러스터를 이루는 미네랄들 위치 저장
			group.clear();
			dfs(i, j);

			// 2. group에 저장된 미네랄 좌표에서 각 x좌표당 가장 낮은 y좌표를 가진 값 구하기
			vector<int> col_each_row(c, -1);
			for (auto &p : group) {
				col_each_row[p.second] = max(col_each_row[p.second], p.first);
				arr[p.first][p.second] = '.';
			}

			// 3. group 미네랄 좌표로부터 몇 칸 떨어질 것인지 확인
			// 다른 미네랄과 부딪히지 않아야하며, 빈칸에 안착해야함
			int y = 0;
			int lowest_gap = r;
			for (int k = 0; k < c; k++) {
				if (col_each_row[k] == -1) continue;
				for (y = col_each_row[k]; y < r && arr[y][k] == '.'; y++);
				lowest_gap = min(lowest_gap, y - col_each_row[k] - 1);
			}

			// 4. (3)에서 lowest_gap만큼 group에 있는 미네랄 좌표 옮기기
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