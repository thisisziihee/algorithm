#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
int arr[500][500][2];	// (i, j)위치의 타일 값 저장
bool visited[500][500];	// (i, j)를 방문했는지 체크
pair<int, int> before[500][500];	// (i, j) 위치를 방문하기 전에 어디 있었는지 좌표 저장
int dist[500][500];		// (i, j)위치에 몇 번 건너서 도착했는지 저장

// 짝수줄(y값 홀수)
int dy1[6] = { -1, -1, 0, 1, 1, 0 };
int dx1[6] = { 0, 1, 1, 1, 0, -1 };

// 홀수줄(y값 짝수)
int dy0[6] = { -1, -1, 0, 1, 1, 0 };
int dx0[6] = { -1, 0, 1, 0, -1, -1 };


// 이동하려는 (y, x) 좌표가 유효한 범위 안에 있는지 확인
bool checkRange(int y, int x) {
	if (y < 0 || y >= n) return false;
	else {
		if ((y % 2 == 0) && (x < 0 || x >= n)) return false;
		if ((y % 2 == 1) && (x < 0 || x >= n - 1))return false;
	}
	return true;
}

// 기존 위치(y, x) 와 이동하려는 위치(ny, nx)에서 공유하는 변끼리 숫자가 같은지 확인
bool checkSame(int y, int x, int ny, int nx) {
	if (y == ny) {
		// 왼쪽 타일과의 비교
		if (x > nx && arr[y][x][0] == arr[ny][nx][1]) return true;
		// 오른쪽 타일과의 비교
		if (x < nx && arr[y][x][1] == arr[ny][nx][0]) return true;
	}
	else {
		if (y % 2 == 0) {
			if (x == nx && arr[y][x][1] == arr[ny][nx][0]) return true;
			if (x > nx && arr[y][x][0] == arr[ny][nx][1]) return true;
		}
		else {
			if (x == nx && arr[y][x][0] == arr[ny][nx][1]) return true;
			if (x < nx && arr[y][x][1] == arr[ny][nx][0]) return true;
		}
	}
	return false;
}


int numbering(int i, int j) {
	// i가 짝수 줄인 경우, (i-2, j-2)번호 + (i-1)번째 줄의 n + j
	// i가 홀수 줄인 경우, (i-1, j-1)번호 + j
	int ans = (i / 2)*(n * 2 - 1);
	if (i % 2 == 1) ans += n;
	ans += j + 1;
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			cin >> arr[i][j][0];
			cin >> arr[i][j][1];
		}
		if (i % 2 == 0) {
			cin >> arr[i][n - 1][0];
			cin >> arr[i][n - 1][1];
		}
	}

	queue< pair<int, int> > Q;
	visited[0][0] = true;
	dist[0][0] = 1;
	Q.push(make_pair(0, 0));

	int x, y, nx, ny;
	while (!Q.empty()) {
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();
		for (int i = 0; i < 6; i++) {
			if (y % 2 == 0) {
				ny = y + dy0[i];
				nx = x + dx0[i];
			}
			else {
				ny = y + dy1[i];
				nx = x + dx1[i];
			}

			if (!checkRange(ny, nx)) continue;
			if (visited[ny][nx]) continue;
			if (!checkSame(y, x, ny, nx)) continue;

			visited[ny][nx] = true;
			dist[ny][nx] = dist[y][x] + 1;
			before[ny][nx] = make_pair(y, x);
			Q.push(make_pair(ny, nx));
		}
	}

	// 마지막 줄의 마지막 타일로 이동할 수 없는 경우 번호가 가장 큰 타일로 이동한다.
	// 가장 마지막 타일로 이동했으면 while문에 진입할 수 없고,
	// 이동하지 못했으면 방문했던 가장 큰 타일이 나올 때 까지 while문 진행
	// 따라서 (y, x) 에는 마지막 타일의 좌표가 저장된다.
	x = n - 1; y = n - 1;
	while (visited[y][x] == false) {
		x -= 1;
		if (x < 0) {
			y -= 1;
			x = n - 1;
			if (y % 2 == 1) {
				x -= 1;
			}
		}
	}

	// (0, 0) ~ (y, x) 마지막 타일까지 경로 길이
	cout << dist[y][x] << endl;

	// 마지막 타일부터 시작해서 이전의 타일들을 차례로 스택에 넣음
	stack< pair<int, int> > ans;
	while (!(x == 0 && y == 0)) {
		ans.push(make_pair(y, x));
		auto p = before[y][x];
		y = p.first;
		x = p.second;
	}
	ans.push(make_pair(y, x));

	// 스택에 하나씩 꺼내서 해당 좌표의 번호 출력
	while (!ans.empty()) {
		cout << numbering(ans.top().first, ans.top().second) << " ";
		ans.pop();
	}
	return 0;
}