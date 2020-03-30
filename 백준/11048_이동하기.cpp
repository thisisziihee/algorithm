/*
준규는 N×M 크기의 미로에 갇혀있다. 미로는 1×1크기의 방으로 나누어져 있고, 각 방에는 사탕이 놓여져 있다. 
미로의 가장 왼쪽 윗 방은 (1, 1)이고, 가장 오른쪽 아랫 방은 (N, M)이다.

준규는 현재 (1, 1)에 있고, (N, M)으로 이동하려고 한다. 
준규가 (r, c)에 있으면, (r+1, c), (r, c+1), (r+1, c+1)로 이동할 수 있고, 
각 방을 방문할 때마다 방에 놓여져있는 사탕을 모두 가져갈 수 있다. 또, 미로 밖으로 나갈 수는 없다.

준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수의 최댓값을 구하시오.

입력
첫째 줄에 미로의 크기 N, M이 주어진다. (1 ≤ N, M ≤ 1,000)
둘째 줄부터 N개 줄에는 총 M개의 숫자가 주어지며, r번째 줄의 c번째 수는 (r, c)에 놓여져 있는 사탕의 개수이다. 
사탕의 개수는 0보다 크거나 같고, 100보다 작거나 같다.

출력
첫째 줄에 준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수를 출력한다.
*/

#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector< vector<int> > arr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	vector< vector<int> > ans(n, vector<int>(m, 0));
	ans[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) ans[i][0] = ans[i - 1][0] + arr[i][0];
	for (int i = 1; i < m; i++) ans[0][i] = ans[0][i - 1] + arr[0][i];

	int dx[3] = { 0, 1, 1 };
	int dy[3] = { 1, 0, 1 };
	int temp;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			temp = max(ans[i - 1][j - 1], ans[i][j - 1]);
			temp = max(temp, ans[i - 1][j]);
			ans[i][j] = temp + arr[i][j];
		}
	}

	cout << ans[n-1][m-1] << endl;
	return 0;
}