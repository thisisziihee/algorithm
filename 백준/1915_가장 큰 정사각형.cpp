/*
n×m의 0, 1로 된 배열이 있다. 이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.
0	1	0	0
0	1	1	1
1	1	1	0
0	0	1	0
위와 같은 예제에서는 가운데의 2×2 배열이 가장 큰 정사각형이다.

입력
첫째 줄에 n, m(1 ≤ n, m ≤ 1,000)이 주어진다. 다음 n개의 줄에는 m개의 숫자로 배열이 주어진다.

출력
첫째 줄에 가장 큰 정사각형의 넓이를 출력한다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector< vector<int> > arr;
vector< vector<int> > dp;

int whoisSmaller(int y, int x) {
	int ans = 2147000000;
	int dx[4] = { -1, 0, -1, 0 };
	int dy[4] = { -1, -1, 0, 0 };
	for (int i = 0; i < 3; i++) {
		int xx, yy;
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
			ans = min(ans, arr[yy][xx]);
		}
	}
	if (ans == 2147000000) ans = 0;
	return ans;
}

int main() {
	cin >> n >> m;
	arr = vector< vector<int> > (n, vector<int>(m, -1));
	string temp;
	int val = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j] - 48;
			if (arr[i][j] == 1) val = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


	dp = vector< vector<int> > (n, vector<int>(m, 0));

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (arr[i][j] != 0) {
				arr[i][j] = whoisSmaller(i, j) + 1;
				val = max(val, arr[i][j]);
			}
		}
	}

	cout << val * val << endl;
}