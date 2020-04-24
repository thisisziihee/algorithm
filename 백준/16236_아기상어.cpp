#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[20][20];
bool visited[20][20];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

// �Ʊ����� ���� ��ġ, ũ��, ���ݱ��� ���� ����� �� ����
struct Shark {
	int y, x, size, ate;
	void sizeUp() {
		ate = 0;
		size += 1;
	}
};

// �Ʊ�� �����̷��� ��ǥ�� ���� ����
// Q�� �ְ� ������ ĭ�� ���� ���� ���� �ͺ��� �����
struct State {
	int y, x, dis;
	
	State(int a, int b, int c) {
		y = a; x = b; dis = c;
	}

	bool operator<( const State &bb) const{
		if (dis == bb.dis) {
			if (y == bb.y) return x > bb.x;
			else return y > bb.y;
		}
		else return dis > bb.dis;
	}
};

int main() {
	cin >> n;
	
	Shark S;
	priority_queue<State> Q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				S.y = i; S.x = j; S.size = 2; S.ate = 0;
				arr[i][j] = 0;
			}
		}
	}

	Q.push(State(S.y, S.x, 0));
	int y, x, dis;
	int ans = 0;

	while (!Q.empty()) {

		State temp = Q.top();
		Q.pop();

		// �̵��Ϸ��� ��ġ
		y = temp.y;
		x = temp.x;
		dis = temp.dis;

		// �Ʊ�� �̵��� (y, x) ��ǥ�� ����Ⱑ ������, �Ʊ���� �۾Ƽ� ���� �� �ִ� ���
		if (arr[y][x] != 0 && arr[y][x] < S.size) {
			
			// 1. �Ʊ� �� ����Ⱑ �ִ� (y,x) ��ġ�� �ű�� ����� ����
			S.ate += 1;
			S.y = y;
			S.x = x;
			
			// 2. �ش� ����⸦ �԰���, ��������� �� �ִ��� Ȯ��
			if (S.ate == S.size) S.sizeUp();

			// 3. ����� ���� �ڸ� ����ֱ�
			arr[y][x] = 0;

			// 4. �ٽ� ���� �Ʊ����� ��ġ (y, x)���� ���� ��ġ�� Ž���ؾ��ϹǷ� visited �迭 �ʱ�ȭ
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					visited[i][j] = false;
				}
			}

			// 5. Q�� ����ִ� ��ǥ ����
			// ���� Q���� ������ �Ʊ� ��� ��ġ(pre_y, pre_x)���� �̵��� �� �ִ� ��ǥ�鸸 ����
			// �׷��� ���� (y, x)��ġ�� �̵��߱� ������, ������ Q�� �ִ� ��ǥ�� ���ǹ��ϹǷ� Q �����
			while (!Q.empty()) Q.pop();

			// 6. (original_y, original_x) -> (y, x) �̵��ϱ� ���� ��ģ ĭ�� ���� ����
			// �ʱ��� �Ʊ��� ��ġ���� ���� �Ʊ��� ��ġ�� �̵��ϱ���� ��� ĭ�� ���ƴ���
			ans = dis;
		}

		// (y, x)���� �������� �̵��� ��ġ Ž��
		// 1. ���� ��ġ (y, x)�� ����Ⱑ �ְ� �װ��� ���� ���
		// 2. ������ ���� ���ϰ� �������⸸ �� ���
		// ���� ��ġ (y, x)���� �����¿� ������ ĭ�߿� ������ �� �ִ� ��ġ Ž��
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[ny][nx] > S.size) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = true;
			Q.push(State(ny, nx, dis + 1));
		}
	}
	cout << ans << endl;
}