#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
char arr[50][50];
int ans = -1;


// 8x8 ü������ B�� �����ϴ� ���� W�� �����ϴ� ���� ������.
// �ش� ü���� board���� B�� �����ϴ� �Ͱ� W�� �����ϴ� �� �߿� �ٽ� ĥ�ϴ� Ƚ���� ���� ���� ��ȯ�Ѵ�.
int count_8x8(vector< vector<char> > board) {

	char now, before;
	int cnt_B = 0, cnt_W = 0;
	vector< vector<char> > temp(board);

	// 1. B�� �����ϴ� ���
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


	// 2. W�� �����ϴ� ���
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


// ���޹��� ������ arr[i][j]�������� 8x8 �������� ü������ �����.
// ���� ü������ count_8x8 �Լ��� �Ѱܼ� �ش� ü���ǿ��� �ּ� ĥ�ϴ� Ƚ���� temp�� �����Ѵ�.
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


// �־��� �迭 arr���� 8x8 ũ���� ü������ ���۵� �� �ִ� ���� ������ ü���� �����.
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