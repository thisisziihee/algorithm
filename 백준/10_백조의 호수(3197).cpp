#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m;
vector<string> arr;

queue< pair<int, int> > water;
queue< pair<int, int> > next_water;
vector< vector<bool> > water_visited;

queue< pair<int, int> > swan;
queue< pair<int, int> > next_swan;
vector< vector<bool> > swan_visited;

int sx1 = -1, sy1, sx2, sy2;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void solution() {
	int day = 0;
	swan.push(make_pair(sy1, sx1));
	swan_visited[sy1][sx1] = true;

	for (day = 0;; day++) {

		while (!water.empty()) {
			int y = water.front().first;
			int x = water.front().second;
			arr[y][x] = '.';
			water.pop();

			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if (water_visited[ny][nx]) continue;

				// (y,x)와 인접한 칸이 아직 얼음 -> 다음 날에 물로 변함 next_water.push
				if (arr[ny][nx] == 'X') {
					water_visited[ny][nx] = true;
					next_water.push(make_pair(ny, nx));
				}
				// (y, x)와 인접한 칸이 물 -> water.push
				else {
					water_visited[ny][nx] = true;
					water.push(make_pair(ny, nx));
				}
			}
		}


		while (!swan.empty()) {
			int y = swan.front().first;
			int x = swan.front().second;
			swan.pop();

			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				if (swan_visited[ny][nx]) continue;

				// (y, x) 상하좌우 칸이 얼음 -> 다음 날에는 지나갈 수 있음 next_swan.push
				if (arr[ny][nx] == 'X') {
					swan_visited[ny][nx] = true;
					next_swan.push(make_pair(ny, nx));
				}
				else{
					swan_visited[ny][nx] = true;
					swan.push(make_pair(ny, nx));
				}
			}
		}

		if (swan_visited[sy2][sx2]) {
			cout << day << endl;
			break;
		}

		swan = next_swan;
		water = next_water;

		next_swan = queue< pair<int, int> >();
		next_water = queue< pair<int, int> >();
	}
}

int main() {
	cin >> n >> m;
	
	arr = vector<string>(n, "");
	water_visited = swan_visited = vector< vector<bool> >(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				if (sx1 == -1) { sx1 = j;  sy1 = i; }
				else { sx2 = j; sy2 = i; }
				arr[i][j] = '.';
			}
			if (arr[i][j] == '.') {
				water.push(make_pair(i, j));
				water_visited[i][j] = true;
			}
		}
	}

	solution();
}