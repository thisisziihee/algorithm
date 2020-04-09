/*
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.
- 정사각형은 서로 겹치면 안 된다.
- 도형은 모두 연결되어 있어야 한다.
- 정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
- 정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.


아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.
테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.
테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)
둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. 
i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector< vector<int> > arr;
vector< vector<int> > check;
int ans = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void solution(int y, int x, int sum, int cnt) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}
	else {
		int xx, yy;
		for (int k = 0; k < 4; k++) {
			xx = x + dx[k];
			yy = y + dy[k];
			if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
				if (check[yy][xx] == 0) {
					check[yy][xx] = 1;
					solution(yy, xx, sum + arr[yy][xx], cnt + 1);
					check[yy][xx] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	arr = vector< vector<int> > (n, vector<int>(m, 0));
	check = vector< vector<int> >(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j + 2 < m) {
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
				if (i + 1 < n) ans = max(ans, temp + arr[i + 1][j+1]);
				if (i - 1 < n && i - 1 >= 0) ans = max(ans, temp + arr[i - 1][j+1]);
			}
			if (i + 2 < n) {
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
				if (j + 1 < m) ans = max(ans, temp + arr[i + 1][j + 1]);
				if (j - 1 < m && j - 1 >= 0) ans = max(ans, temp + arr[i + 1][j - 1]);
			}
			check[i][j] = 1;
			solution(i, j, arr[i][j], 1);
			check[i][j] = 0;
		}
	}
	
	cout << ans << endl;
}