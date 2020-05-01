#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int arr[50][50];
int copied[50][50];
bool visited[50][50] = { false };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector< pair<int, int> > virus;


//  0: 바이러스
// -1 : 빈칸
// -2 : 벽
void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) copied[i][j] = -1;
			else if(arr[i][j] == 1) copied[i][j] = -2;
			else copied[i][j] = 0;
		}
	}
}

int main() {
	cin >> n >> m;

	int ans = -1;
	int empty_space = 0;

	// n <= 50. m <= 10
	// n x n 크기의 연구실에 m개의 바이러스. 0 빈칸. 1 벽. 2 바이러스가 들어올 수 있는 공간
	// 2의 위치에 m개의 바이러스 투척. 연구실 전체가 감염되는데 걸리는 최소 시간
	// 바이러스 총 개수 중에 m개는 활성 바이러스 나머지느 비활성 바이러스

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
			else if (arr[i][j] == 0) empty_space += 1;
		}
	}


	// 1. m개의 활성 바이러스 고르기
	vector<int> order(virus.size(), 0);
	for (int i = 0; i < m; i++) {
		order[i] = 1;
	}
	sort(order.begin(), order.end());


	// 2. m개의 바이러스 골랐으면 감염 시간 체크
	do {
		queue< pair<int, int> > V;

		// (1). 오리지날 연구소 배열 복사. 빈칸 체크. 비활성화 바이러스 체크
		copy();
		memset(visited, false, sizeof(visited));


		// (2). 활성화 바이러스는 큐에 넣고 copied에 0초 표시. 비활성화 바이러스는 copied에 -2초 표시
		for (int i = 0; i < virus.size(); i++) {
			if (order[i] == 1) {
				V.push(make_pair(virus[i].first, virus[i].second));
				visited[virus[i].first][virus[i].second] = true;
			}
			else copied[virus[i].first][virus[i].second] = -3;
		}


		// (3). 큐에서 하나씩 꺼내서 시간 체크
		int y, x, ny, nx;
		int all_infected_sec = 0;
		int temp = 0;

		while (!V.empty()) {
			y = V.front().first;
			x = V.front().second;
			V.pop();

			for (int k = 0; k < 4; k++) {
				ny = y + dy[k];
				nx = x + dx[k];

				// 범위를 벗어나거나 이미 방문했던 지점, 벽인 경우에는 continue;
				if (ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
				if (visited[ny][nx]) continue;

				if (copied[ny][nx] == -1) {
					visited[ny][nx] = true;
					copied[ny][nx] = copied[y][x] + 1;
					if (copied[ny][nx] > all_infected_sec) all_infected_sec = copied[ny][nx];
					V.push(make_pair(ny, nx));
					temp += 1;
				}
				else if (copied[ny][nx] == -3) {

					visited[ny][nx] = true;
					copied[ny][nx] = copied[y][x] + 1;
					V.push(make_pair(ny, nx));
				}
			}
		}

		// (4). 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우 확인
		// 3번 과정에서 감염시켰는데도 빈칸이 존재하는 경우
		if (temp == empty_space) {
			if (ans == -1 || ans > all_infected_sec) ans = all_infected_sec;
		}

	} while (next_permutation(order.begin(), order.end()));

	cout << ans << endl;
	return 0;
}