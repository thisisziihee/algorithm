#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>
#include <string>

using namespace std;

int n, m;
vector<string> arr;

// ���� ����(ry, rx) �Ķ� ����(by, bx)�� �ش� ������ �� �� ��￩�� �����ߴ��� Ȯ��
// �� ���� �湮���� ���� ���� -1, �湮�ߴٸ� �� ������ �����Ѱ��� Ƚ�� ����
int visited[10][10][10][10];


// �� �� �� ��
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };	


// pair< ����������, ���ۿ� ������ > ��ȯ�Ѵ�.
pair<bool, bool> move(vector<string> &board, int dir, int &y, int &x) {
	if (board[y][x] == '.') return make_pair(false, false);
	bool moved = false;
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// (ny, nx) ��ġ�� ���� ������ ����� ���
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) return make_pair(moved, false);

		// (ny, nx) ��ġ�� ���� ���
		if (board[ny][nx] == '#') return make_pair(moved, false);

		// �̵��Ϸ��� ���� �̹� �ٸ� ������ �ִ� ���
		else if (board[ny][nx] == 'R' || board[ny][nx] == 'B')return make_pair(moved, false);

		// ��ĭ���� �̵� : �̵��Ϸ��� ��ĭ���� ������ �ű��.
		else if (board[ny][nx] == '.') {
			swap(board[ny][nx], board[y][x]);
			x = nx;
			y = ny;
			moved = true;
		}

		// ������ ���ۿ� ���� ���
		else if (board[ny][nx] == 'O') {
			board[y][x] = '.';
			moved = true;
			return make_pair(moved, true);
		}
	}
}

// dir �������� �����̴� �Ϳ� ���ؼ� üũ�� �ϴ� ���̴ϱ� board�� �ּҰ����� �޾ƿ��� �ʰ�, �׳� ���� ���� �޴´�.
pair<bool, bool> check(vector<string> board, int &ry, int &rx, int &by, int &bx, int dir) {
	board[ry][rx] = 'R';
	board[by][bx] = 'B';

	bool red_hole = false, blue_hole = false;
	while (true) {
		// dir �������� ���� ������ �Ķ� ������ �������� 
		// first : ��ĭ���� ����������(true) �������� �������� ���ߴ���(false)
		// second : ���ۿ� ������ Ȯ���Ѵ�.
		auto red = move(board, dir, ry, rx);
		auto blue = move(board, dir, by, bx);
		
		// �� ������ �� �̻� �̵����� ���� �� while�� Ż��
		if (red.first == false && blue.first == false) break;

		// �� ������ ���ۿ� �������� Ȯ��
		if (red.second) red_hole = true;
		if (blue.second) blue_hole = true;
	}
	return make_pair(red_hole, blue_hole);
}

int main() {
	cin >> n >> m;
	arr = vector<string>(n, "");

	int ry, rx, by, bx;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'R') {
				ry = i; rx = j;
				arr[i][j] = '.';
			}
			if (arr[i][j] == 'B') {
				by = i; bx = j;
				arr[i][j] = '.';
			}
		}
	}

	// ���� ����, �Ķ� ������ ���� ��ġ�� Q�� �������
	queue< tuple<int, int, int, int> > Q;
	Q.emplace(ry, rx, by, bx);

	memset(visited, -1, sizeof(visited));
	visited[ry][rx][by][bx] = 0;
	
	bool ans_found = false;
	int ans = -1;

	while (!Q.empty()) {
		tie(ry, rx, by, bx) = Q.front();
		Q.pop();

		// ���� �������� ��ġ(ry, rx, by, bx)�� ���ؼ� �����¿� �̵��ϸ鼭 �˻�
		for (int dir = 0; dir < 4; dir++) {
			bool red_hole = false, blue_hole = false;
			int nry = ry, nrx = rx, nby = by, nbx = bx;
			
			// ���� ������ arr�� ���ؼ� �������� dir �������� �̵��Ͽ��� ��, ���ۿ� �������� �ƴ��� Ȯ��
			// �� ������ ���ۿ� �������� ���θ� ��ȯ�Ѵ�.
			tie(red_hole, blue_hole) = check(arr, nry, nrx, nby, nbx, dir);
			
			// �Ķ� ������ ���ۿ� �������� continue;
			if (blue_hole) continue;

			// ���� ������ ���ۿ� �������� while�� Ż��
			// ���� ���� ���� �ּڰ��̹Ƿ� �ٷ� ���͵� ��.
			// ������ Ƚ���� (ry, rx, by, bx)�� ������ Ƚ�� + 1
			if (red_hole) {
				ans_found = true;
				ans = visited[ry][rx][by][bx] + 1;
				break;
			}

			// �̹� �湮�ߴ� �����̶�� continue
			if (visited[nry][nrx][nby][nbx] != -1) continue;

			// ó�� �湮�ߴٸ� ������� ������ Ƚ�� + 1
			Q.emplace(nry, nrx, nby, nbx);
			visited[nry][nrx][nby][nbx] = visited[ry][rx][by][bx] + 1;
		}
		if (ans_found) break;
	}
	cout << ans << endl;
	return 0;
}