#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
char arr[50][50];
int ans = -1;


// 8x8 체스판은 B로 시작하는 경우와 W로 시작하는 경우로 나뉜다.
// 해당 체스판 board에서 B로 시작하는 것과 W로 시작하는 것 중에 다시 칠하는 횟수가 적은 값을 반환한다.
int count_8x8(vector< vector<char> > board) {

	char now, before;
	int cnt_B = 0, cnt_W = 0;
	vector< vector<char> > temp(board);

	// 1. B로 시작하는 경우
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) before = 'W';
		else before = 'B';
		for (int j = 0; j < 8; j++) {
			now = temp[i][j];
			if (now == before) {
				if (now == 'W') temp[i][j] = 'B';
				else temp[i][j] = 'W';
				cnt_B += 1;
			}
			before = temp[i][j];
		}
	}


	// 2. W로 시작하는 경우
	temp = board;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) before = 'B';
		else before = 'W';
		for (int j = 0; j < 8; j++) {
			now = temp[i][j];
			if (now == before) {
				if (now == 'W') temp[i][j] = 'B';
				else temp[i][j] = 'W';
				cnt_W += 1;
			}
			before = temp[i][j];
		}
	}

	if (cnt_W > cnt_B) return cnt_B;
	else return cnt_W;
}


// 전달받은 시작점 arr[i][j]에서부터 8x8 사이즈의 체스판을 만든다.
// 만든 체스판은 count_8x8 함수로 넘겨서 해당 체스판에서 최소 칠하는 횟수를 temp에 저장한다.
void make_8x8(int i, int j) {
	vector< vector<char> > board(8, vector<char>(8, '.'));
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			board[y][x] = arr[i + y][j + x];
		}
	}
	int temp = count_8x8(board);
	if (ans == -1 || ans > temp) ans = temp;
}


// 주어진 배열 arr에서 8x8 크기의 체스판이 시작될 수 있는 범위 내에서 체스판 만든다.
void solution() {
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			make_8x8(i, j);
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	solution();
	cout << ans << endl;
	return 0;
}