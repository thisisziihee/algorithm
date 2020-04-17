#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
int arr[500][500][2];	// (i, j)��ġ�� Ÿ�� �� ����
bool visited[500][500];	// (i, j)�� �湮�ߴ��� üũ
pair<int, int> before[500][500];	// (i, j) ��ġ�� �湮�ϱ� ���� ��� �־����� ��ǥ ����
int dist[500][500];		// (i, j)��ġ�� �� �� �ǳʼ� �����ߴ��� ����

// ¦����(y�� Ȧ��)
int dy1[6] = { -1, -1, 0, 1, 1, 0 };
int dx1[6] = { 0, 1, 1, 1, 0, -1 };

// Ȧ����(y�� ¦��)
int dy0[6] = { -1, -1, 0, 1, 1, 0 };
int dx0[6] = { -1, 0, 1, 0, -1, -1 };


// �̵��Ϸ��� (y, x) ��ǥ�� ��ȿ�� ���� �ȿ� �ִ��� Ȯ��
bool checkRange(int y, int x) {
	if (y < 0 || y >= n) return false;
	else {
		if ((y % 2 == 0) && (x < 0 || x >= n)) return false;
		if ((y % 2 == 1) && (x < 0 || x >= n - 1))return false;
	}
	return true;
}

// ���� ��ġ(y, x) �� �̵��Ϸ��� ��ġ(ny, nx)���� �����ϴ� ������ ���ڰ� ������ Ȯ��
bool checkSame(int y, int x, int ny, int nx) {
	if (y == ny) {
		// ���� Ÿ�ϰ��� ��
		if (x > nx && arr[y][x][0] == arr[ny][nx][1]) return true;
		// ������ Ÿ�ϰ��� ��
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
	// i�� ¦�� ���� ���, (i-2, j-2)��ȣ + (i-1)��° ���� n + j
	// i�� Ȧ�� ���� ���, (i-1, j-1)��ȣ + j
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

	// ������ ���� ������ Ÿ�Ϸ� �̵��� �� ���� ��� ��ȣ�� ���� ū Ÿ�Ϸ� �̵��Ѵ�.
	// ���� ������ Ÿ�Ϸ� �̵������� while���� ������ �� ����,
	// �̵����� �������� �湮�ߴ� ���� ū Ÿ���� ���� �� ���� while�� ����
	// ���� (y, x) ���� ������ Ÿ���� ��ǥ�� ����ȴ�.
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

	// (0, 0) ~ (y, x) ������ Ÿ�ϱ��� ��� ����
	cout << dist[y][x] << endl;

	// ������ Ÿ�Ϻ��� �����ؼ� ������ Ÿ�ϵ��� ���ʷ� ���ÿ� ����
	stack< pair<int, int> > ans;
	while (!(x == 0 && y == 0)) {
		ans.push(make_pair(y, x));
		auto p = before[y][x];
		y = p.first;
		x = p.second;
	}
	ans.push(make_pair(y, x));

	// ���ÿ� �ϳ��� ������ �ش� ��ǥ�� ��ȣ ���
	while (!ans.empty()) {
		cout << numbering(ans.top().first, ans.top().second) << " ";
		ans.pop();
	}
	return 0;
}