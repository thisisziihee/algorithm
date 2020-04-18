#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m;
vector<string> arr;
vector< vector<bool> > visited;

// [cnt][0] : cnt 영역에 있는 늑대의 수
// [cnt][1] : cnt 영역에 있는 양의 수
int ans[250 * 250][2];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void bfs(int y, int x, int cnt) {
	queue< pair<int, int> > Q;
	Q.push(make_pair(y, x));
	visited[y][x] = true;
	while (!Q.empty()) {
		int yy = Q.front().first;
		int xx = Q.front().second;
		Q.pop();
		if (arr[yy][xx] == 'v') ans[cnt][0] += 1;
		else if (arr[yy][xx] == 'o') ans[cnt][1] += 1;
		for (int k = 0; k < 4; k++) {
			int ny = yy + dy[k];
			int nx = xx + dx[k];
			if (nx < 0 || ny < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == '#')continue;
			if (visited[ny][nx]) continue;
			Q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
}


int main() {
	cin >> n >> m;
	arr = vector<string>(n, "");
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	visited = vector< vector<bool> >(n, vector<bool>(m, false));

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != '#' && !visited[i][j]) {
				// (i,j)에서 BFS 진행
				// cnt : 같은 영역에 있는 칸들은 모두 cnt 번호를 갖게 됨
				cnt += 1;
				bfs(i, j, cnt);
			}
		}
	}

	int v = 0;
	int o = 0;
	for (int i = 1; i <= cnt; i++) {
		if (ans[i][0] >= ans[i][1]) {
			v += ans[i][0];
		}
		else {
			o += ans[i][1];
		}
	}

	cout << o << " " << v << endl;
}