#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>
#include <string>

using namespace std;

int n, m;
vector<string> arr;

// 빨간 구슬(ry, rx) 파란 구슬(by, bx)가 해당 지점을 몇 번 기울여서 도착했는지 확인
// 한 번도 방문하지 않은 곳은 -1, 방문했다면 몇 번만에 도착한건지 횟수 저장
int visited[10][10][10][10];


// 왼 오 위 아
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };	


// pair< 움직였는지, 구멍에 들어갔는지 > 반환한다.
pair<bool, bool> move(vector<string> &board, int dir, int &y, int &x) {
	if (board[y][x] == '.') return make_pair(false, false);
	bool moved = false;
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// (ny, nx) 위치가 범위 밖으로 벗어나는 경우
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) return make_pair(moved, false);

		// (ny, nx) 위치가 벽인 경우
		if (board[ny][nx] == '#') return make_pair(moved, false);

		// 이동하려는 곳에 이미 다른 구슬이 있는 경우
		else if (board[ny][nx] == 'R' || board[ny][nx] == 'B')return make_pair(moved, false);

		// 빈칸으로 이동 : 이동하려는 빈칸으로 구슬을 옮긴다.
		else if (board[ny][nx] == '.') {
			swap(board[ny][nx], board[y][x]);
			x = nx;
			y = ny;
			moved = true;
		}

		// 구슬이 구멍에 빠진 경우
		else if (board[ny][nx] == 'O') {
			board[y][x] = '.';
			moved = true;
			return make_pair(moved, true);
		}
	}
}

// dir 방향으로 움직이는 것에 대해서 체크만 하는 것이니까 board는 주소값으로 받아오지 않고, 그냥 벡터 값만 받는다.
pair<bool, bool> check(vector<string> board, int &ry, int &rx, int &by, int &bx, int dir) {
	board[ry][rx] = 'R';
	board[by][bx] = 'B';

	bool red_hole = false, blue_hole = false;
	while (true) {
		// dir 방향으로 빨간 구슬과 파란 구슬을 움직여서 
		// first : 빈칸으로 움직였는지(true) 벽때문에 움직이지 못했는지(false)
		// second : 구멍에 들어갔는지 확인한다.
		auto red = move(board, dir, ry, rx);
		auto blue = move(board, dir, by, bx);
		
		// 두 구슬이 더 이상 이동하지 못할 때 while문 탈출
		if (red.first == false && blue.first == false) break;

		// 각 구슬이 구멍에 빠졌는지 확인
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

	// 빨간 구슬, 파란 구슬의 현재 위치를 Q에 집어넣음
	queue< tuple<int, int, int, int> > Q;
	Q.emplace(ry, rx, by, bx);

	memset(visited, -1, sizeof(visited));
	visited[ry][rx][by][bx] = 0;
	
	bool ans_found = false;
	int ans = -1;

	while (!Q.empty()) {
		tie(ry, rx, by, bx) = Q.front();
		Q.pop();

		// 현재 구슬들의 위치(ry, rx, by, bx)에 대해서 상하좌우 이동하면서 검사
		for (int dir = 0; dir < 4; dir++) {
			bool red_hole = false, blue_hole = false;
			int nry = ry, nrx = rx, nby = by, nbx = bx;
			
			// 현재 보드판 arr에 대해서 구슬들이 dir 방향으로 이동하였을 때, 구멍에 빠지는지 아닌지 확인
			// 두 구슬의 구멍에 빠졌는지 여부를 반환한다.
			tie(red_hole, blue_hole) = check(arr, nry, nrx, nby, nbx, dir);
			
			// 파란 구슬이 구멍에 빠졌으면 continue;
			if (blue_hole) continue;

			// 빨간 구슬만 구멍에 빠졌으면 while문 탈출
			// 빨리 구할 수록 최솟값이므로 바로 나와도 됨.
			// 움직인 횟수는 (ry, rx, by, bx)가 움직인 횟수 + 1
			if (red_hole) {
				ans_found = true;
				ans = visited[ry][rx][by][bx] + 1;
				break;
			}

			// 이미 방문했던 지점이라면 continue
			if (visited[nry][nrx][nby][nbx] != -1) continue;

			// 처음 방문했다면 현재까지 움직인 횟수 + 1
			Q.emplace(nry, nrx, nby, nbx);
			visited[nry][nrx][nby][nbx] = visited[ry][rx][by][bx] + 1;
		}
		if (ans_found) break;
	}
	cout << ans << endl;
	return 0;
}