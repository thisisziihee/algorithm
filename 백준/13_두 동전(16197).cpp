#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

int n, m;
vector< vector<char> > arr;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = -1;

int solution(int step, int y1, int x1, int y2, int x2) {
	if (step == 11) return -1;
	
	bool fall1 = false, fall2 = false;
	if (x1 < 0 || y1 < 0 || x1 >= m || y1 >= n) fall1 = true;
	if (x2 < 0 || y2 < 0 || x2 >= m || y2 >= n) fall2 = true;


	if (fall1 && fall2) return -1;
	if ((fall1 && !fall2) || (!fall1 && fall2)) return step;

	for (int i = 0; i < 4; i++) {
		int ny1 = y1 + dy[i];
		int nx1 = x1 + dx[i];
		int ny2 = y2 + dy[i];
		int nx2 = x2 + dx[i];

		if (ny1 >= 0 && ny1 < n && nx1 >= 0 && nx1 < m && arr[ny1][nx1] == '#') {
			ny1 = y1;
			nx1 = x1;
		}
		if (ny2 >= 0 && ny2 < n && nx2 >= 0 && nx2 < m && arr[ny2][nx2] == '#') {
			ny2 = y2;
			nx2 = x2;
		}

		int temp = solution(step + 1, ny1, nx1, ny2, nx2);
		if (temp == -1) continue;
		if (ans == -1 || ans > temp) ans = temp;
	}
	return ans;
}


int main() {
	cin >> n >> m;

	arr = vector< vector<char> >(n, vector<char>(m, '.'));
	int x1 = -1, x2 = -1, y1 = -1, y2 = -1;

	string temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j];
			if (arr[i][j] == 'o') {
				if (x1 == -1) {
					x1 = j; y1 = i;
				}
				else {
					x2 = j; y2 = i;
				}
				arr[i][j] = '.';
			}

		}
	}


	cout << solution(0, y1, x1, y2, x2) << endl;

}