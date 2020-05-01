#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int arr[50][50];
int copied[50][50];
bool visited[50][50] = { false };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector< pair<int, int> > virus;


//  0: ���̷���
// -1 : ��ĭ
// -2 : ��
void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) copied[i][j] = -1;
			else if(arr[i][j] == 1) copied[i][j] = -2;
			else copied[i][j] = 0;
		}
	}
}

int main() {
	cin >> n >> m;

	int ans = -1;
	int empty_space = 0;

	// n <= 50. m <= 10
	// n x n ũ���� �����ǿ� m���� ���̷���. 0 ��ĭ. 1 ��. 2 ���̷����� ���� �� �ִ� ����
	// 2�� ��ġ�� m���� ���̷��� ��ô. ������ ��ü�� �����Ǵµ� �ɸ��� �ּ� �ð�
	// ���̷��� �� ���� �߿� m���� Ȱ�� ���̷��� �������� ��Ȱ�� ���̷���

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
			else if (arr[i][j] == 0) empty_space += 1;
		}
	}


	// 1. m���� Ȱ�� ���̷��� ����
	vector<int> order(virus.size(), 0);
	for (int i = 0; i < m; i++) {
		order[i] = 1;
	}
	sort(order.begin(), order.end());


	// 2. m���� ���̷��� ������� ���� �ð� üũ
	do {
		queue< pair<int, int> > V;

		// (1). �������� ������ �迭 ����. ��ĭ üũ. ��Ȱ��ȭ ���̷��� üũ
		copy();
		memset(visited, false, sizeof(visited));


		// (2). Ȱ��ȭ ���̷����� ť�� �ְ� copied�� 0�� ǥ��. ��Ȱ��ȭ ���̷����� copied�� -2�� ǥ��
		for (int i = 0; i < virus.size(); i++) {
			if (order[i] == 1) {
				V.push(make_pair(virus[i].first, virus[i].second));
				visited[virus[i].first][virus[i].second] = true;
			}
			else copied[virus[i].first][virus[i].second] = -3;
		}


		// (3). ť���� �ϳ��� ������ �ð� üũ
		int y, x, ny, nx;
		int all_infected_sec = 0;
		int temp = 0;

		while (!V.empty()) {
			y = V.front().first;
			x = V.front().second;
			V.pop();

			for (int k = 0; k < 4; k++) {
				ny = y + dy[k];
				nx = x + dx[k];

				// ������ ����ų� �̹� �湮�ߴ� ����, ���� ��쿡�� continue;
				if (ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
				if (visited[ny][nx]) continue;

				if (copied[ny][nx] == -1) {
					visited[ny][nx] = true;
					copied[ny][nx] = copied[y][x] + 1;
					if (copied[ny][nx] > all_infected_sec) all_infected_sec = copied[ny][nx];
					V.push(make_pair(ny, nx));
					temp += 1;
				}
				else if (copied[ny][nx] == -3) {

					visited[ny][nx] = true;
					copied[ny][nx] = copied[y][x] + 1;
					V.push(make_pair(ny, nx));
				}
			}
		}

		// (4). ��� �� ĭ�� ���̷����� �۶߸� �� ���� ��� Ȯ��
		// 3�� �������� �������״µ��� ��ĭ�� �����ϴ� ���
		if (temp == empty_space) {
			if (ans == -1 || ans > all_infected_sec) ans = all_infected_sec;
		}

	} while (next_permutation(order.begin(), order.end()));

	cout << ans << endl;
	return 0;
}