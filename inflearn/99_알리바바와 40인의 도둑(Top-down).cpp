/*
알리바바는 40인의 도둑으로부터 금화를 훔쳐 도망치고 있습니다. 알리바바는 도망치는 길에 평소에 잘 가지 않던 계곡의 돌다리로 도망가고자 한다.
계곡의 돌다리는 N×N개의 돌들로 구성되어 있다. 각 돌다리들은 높이가 서로 다릅니다.
해당 돌다리를 건널때 돌의 높이 만큼 에너지가 소비됩니다. 이동은 최단거리 이동을 합니다.
즉 현재 지점에서 오른쪽 또는 아래쪽으로만 이동해야 합니다.
N*N의 계곡의 돌다리 격자정보가 주어지면 (1, 1)격자에서 (N, N)까지 가는데 드는 에너지의 최소량을 구하는 프로그램을 작성하세요.

만약 N=3이고, 계곡의 돌다리 격자 정보가 다음과 같다면
3
3 3 5
2 3 4
6 5 2
(1, 1)좌표에서 (3, 3)좌표까지 가는데 드는 최소 에너지는 3+2+3+4+2=14이다.

▣ 입력설명
첫 번째 줄에는 자연수 N(1<=N<=20)이 주어진다.
두 번째 줄부터 계곡의 N*N 격자의 돌다리 높이(10보다 작은 자연수) 정보가 주어진다.
*/

#include <bits/stdc++.h>

using namespace std;

int board[21][21];
int dy[21][21];
int n;

int dfs(int x, int y) {
	if (dy[x][y] > 0) return dy[x][y];
	else if (x == 0 && y == 0) {
		return board[0][0];
	}
	else if (x == 0 && y != 0) {
		// 위의 값만 호출
		return dy[x][y] = dfs(x, y - 1) + board[x][y];
	}
	else if (x != 0 && y == 0) {
		// 오른쪽 값만 호출
		return dy[x][y] = dfs(x - 1, y) + board[x][y];
	}
	else {
		return dy[x][y] = min(dfs(x - 1, y), dfs(x, y - 1)) + board[x][y];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	cout << dfs(n - 1, n - 1) << endl;
}
