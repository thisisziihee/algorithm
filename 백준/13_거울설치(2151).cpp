#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	int n;
	cin >> n;

	vector<string> arr(n);

	// 정점의 정보 저장
	// 문과 거울의 위치가 저장됨
	vector< pair<int, int> > vertex;

	// 정점의 좌표(i, j)가 vertex에서 몇 번째 정점인지 저장
	vector< vector<int> > b(n, vector<int>(n));

	int start = -1, end = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < n; j++) {

			if (arr[i][j] == '#') {
				// 문의 정점 번호
				if (start == -1) start = vertex.size();
				else end = vertex.size();

				vertex.push_back(make_pair(i, j));
				b[i][j] = vertex.size() - 1;
			}
			else if (arr[i][j] == '!') {
				vertex.push_back(make_pair(i, j));
				b[i][j] = vertex.size() - 1;
			}
		}
	}

	int m = vertex.size();

	// 정점들(거울, 문)간에 빛이 서로 통하는지 확인
	vector< vector<bool> > a(m, vector<bool>(m, false));

	for (int i = 0; i < vertex.size(); i++) {
		for (int k = 0; k < 4; k++) {
			int y = vertex[i].first + dy[k];
			int x = vertex[i].second + dx[k];

			while (x >= 0 && y >= 0 && x < n && y < n) {

				// i정점에서 k방향으로 더이상 빛이 통과할 수 없음
				if (arr[y][x] == '*') break;
				
				if (arr[y][x] == '#' || arr[y][x] == '!') {
					// i번째 정점과 i번째에서 k 방향으로 움직인 (y, x)좌표가 빛이 통한다.
					// (y, x)좌표가 몇 번째 정점인지 벡터 b에 저장되어 있음
					a[i][b[y][x]] = true;
				}

				y += dy[k];
				x += dx[k];
			}
		}
	}


	queue<int> Q;

	// start 부터 dist[i]지점까지 갈 때 까지의 이동횟수. 즉, 설치한 거울의 최소 개수가 된다. 
	// 따라서 end 지점은 문이기 때문에 1을 빼줘야한다.
	vector<int> dist(m, -1);
	
	Q.push(start);
	dist[start] = 0;

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		// now와 m개의 정점 중에서 서로 빛이 통하는지 확인
		for (int i = 0; i < m; i++) {
			// now 정점과 i 정점이 서로 빛이 통하는 경우, i지점에 거울을 설치
			if (a[now][i] && dist[i] == -1) {
				dist[i] = dist[now] + 1;
				Q.push(i);
			}
		}
	}

	//
	cout << dist[end]-1 << endl;
	return 0;
}