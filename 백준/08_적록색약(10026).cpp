#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
string arr[100];

int group[100][100];
bool visited[100][100];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void make_group(int i, int j, int cnt) {
	queue< pair<int, int> > Q;
	Q.push(make_pair(i, j));
	int ny, nx, x, y;

	while (!Q.empty()) {
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			ny = y + dy[k];
			nx = x + dx[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[ny][nx]) continue;
			if (group[ny][nx] != 0) continue;

			if (arr[y][x] == 'B' && arr[ny][nx] == 'B') {
				group[ny][nx] = cnt;
				visited[ny][nx] = true;
				Q.push(make_pair(ny, nx));
			}
			else {
				if (arr[y][x] == 'G' && arr[ny][nx] != 'B') {
					group[ny][nx] = cnt;
					visited[ny][nx] = true;
					Q.push(make_pair(ny, nx));
				}
				else if (arr[y][x] == 'R' && arr[ny][nx] != 'B') {
					group[ny][nx] = cnt;
					visited[ny][nx] = true;
					Q.push(make_pair(ny, nx));
				}
			}
		}
	}
}


void make_group2(int i, int j, int cnt) {
	queue< pair<int, int> > Q;
	Q.push(make_pair(i, j));
	int ny, nx, x, y;

	while (!Q.empty()) {
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			ny = y + dy[k];
			nx = x + dx[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[ny][nx]) continue;
			if (group[ny][nx] != 0) continue;
			if (arr[y][x] != arr[ny][nx]) continue;

			group[ny][nx] = cnt;
			visited[ny][nx] = true;
			Q.push(make_pair(ny, nx));
		}
	}
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	memset(visited, false, sizeof(visited));
	memset(group, 0, sizeof(group));
	int ans1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			ans1 += 1;
			make_group(i, j, ans1);
		}
	}


	
	memset(visited, false, sizeof(visited));
	memset(group, 0, sizeof(group));
	int ans2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			ans2 += 1;
			make_group2(i, j, ans2);
		}
	}
	cout << ans2 << " " << ans1 << endl;
}