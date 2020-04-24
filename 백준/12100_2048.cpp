#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector< vector<int> > arr;
void print();


void shift(int move, vector< vector<int> > &a) {
	queue<int>  Q;
	switch (move) {
		// 윗 쪽으로 이동
		case 0: 
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (a[y][x] != 0) {
						Q.push(a[y][x]);
						a[y][x] = 0;
					}
				}

				int y = 0;
				while (!Q.empty()) {
					int now = Q.front();
					if (a[y][x] == 0) {
						a[y][x] = now;
					}
					else if (a[y][x] == now) {
						a[y][x] += now;
						y += 1;
					}
					else {
						y += 1;
						a[y][x] = now;
					}
					Q.pop();
				}
		    }
			break;

		// 아랫쪽으로 이동
		case 1: 
			for (int x = 0; x < n; x++) {
				for (int y = n - 1; y >= 0; y--) {
					if (a[y][x] != 0) {
						Q.push(a[y][x]);
						a[y][x] = 0;
					}
				}

				int y = n - 1;
				while (!Q.empty()) {
					int now = Q.front();
					if (a[y][x] == 0) {
						a[y][x] = now;
					}
					else if (a[y][x] == now) {
						a[y][x] += now;
						y -= 1;
					}
					else {
						y -= 1;
						a[y][x] = now;
					}
					Q.pop();
				}
			}
			break;

		// 오른쪽으로 이동
		case 2:
			for (int y = 0; y < n; y++) {
				for (int x = n - 1; x >= 0; x--) {
					if (a[y][x] != 0) {
						Q.push(a[y][x]);
						a[y][x] = 0;
					}
				}

				int x = n - 1;
				while (!Q.empty()) {
					int now = Q.front();
					if (a[y][x] == 0) {
						a[y][x] = now;
					}
					else if (a[y][x] == now) {
						a[y][x] += now;
						x -= 1;
					}
					else {
						x -= 1;
						a[y][x] = now;
					}
					Q.pop();
				}
			}
			break;

		// 왼쪽으로 이동
		case 3:
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					if (a[y][x] != 0) {
						Q.push(a[y][x]);
						a[y][x] = 0;
					}
				}

				int x = 0;
				while (!Q.empty()) {
					int now = Q.front();
					if (a[y][x] == 0) {
						a[y][x] = now;
					}
					else if (a[y][x] == now) {
						a[y][x] += now;
						x += 1;
					}
					else {
						x += 1;
						a[y][x] = now;
					}
					Q.pop();
				}
			}
			break;
		
		default:
			break;
	}
}


int ans = -1;
void dfs(int level, vector< vector<int> > a) {
	if (level == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) continue;
				if (ans == -1 || ans < a[i][j]) ans = a[i][j];
			}
		}
		return;
	}
	

	vector< vector<int> > copied(a);


	for (int i = 0; i < 4; i++) {
		shift(i, copied);
		dfs(level + 1, copied);
		copied = a;
	}
}


int main() {
	cin >> n ;
	arr = vector< vector<int> >(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, arr);

	cout << ans << endl;
}

/*

4
0 0 0 0
2 2 0 8
0 4 8 8
2 8 8 4


*/