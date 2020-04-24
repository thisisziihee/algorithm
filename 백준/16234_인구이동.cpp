#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int N, L, R;
int arr[100][100];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[100][100] = { false };

queue< tuple<int, int, int> > Q;


int check_neighbor(int y, int x, int cnt) {
	int a = 0, sum = 0;
	tuple<int, int> res;

	queue< pair<int, int> > now;
	now.push(make_pair(y, x));

	while (!now.empty()) {
		int i = now.front().first;
		int j = now.front().second;
		now.pop();

		for (int k = 0; k < 4; k++) {
			int ni = i + dy[k];
			int nj = j + dx[k];

			if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
			if (visited[ni][nj]) continue;

			int temp = abs(arr[i][j] - arr[ni][nj]);

			if (temp >= L && temp <= R) {
				if (!visited[i][j]) {
					visited[i][j] = true;
					Q.emplace(i, j, cnt);
					sum += arr[i][j];
					a += 1;
				}
				visited[ni][nj] = true;
				sum += arr[ni][nj];
				a += 1;

				Q.emplace(ni, nj, cnt);
				now.push(make_pair(ni, nj));
			}
		}
	}
	if (sum == 0 || a <= 1) return 0;
	else return (sum / a);
}


int main() {
	cin >> N >> L >> R;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0, sum, cnt, check;

	while (true) {

		// 1. 현재 arr배열에서 연합을 이루는 국가 있는지 확인
		sum = cnt = check = 0;
		memset(visited, false, sizeof(visited));
		int nara_arr[2500] = { 0 };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;

				// cnt번째 연합 국가에 속한 나라들의 평균값이 반환됨
				int temp = check_neighbor(i, j, check);

				if (temp != 0) {
					nara_arr[check] = temp;
					check += 1;
				}
			}
		}

		if (check == 0 || Q.empty()) break;

		while (!Q.empty()) {
			int y, x, c;
			tie(y, x, c) = Q.front();
			Q.pop();
			arr[y][x] = nara_arr[c];
		}
		ans += 1;
	
	}

	cout << ans << endl;
}