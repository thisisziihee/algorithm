#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	int n;
	cin >> n;

	vector<string> arr(n);

	// ������ ���� ����
	// ���� �ſ��� ��ġ�� �����
	vector< pair<int, int> > vertex;

	// ������ ��ǥ(i, j)�� vertex���� �� ��° �������� ����
	vector< vector<int> > b(n, vector<int>(n));

	int start = -1, end = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < n; j++) {

			if (arr[i][j] == '#') {
				// ���� ���� ��ȣ
				if (start == -1) start = vertex.size();
				else end = vertex.size();

				vertex.push_back(make_pair(i, j));
				b[i][j] = vertex.size() - 1;
			}
			else if (arr[i][j] == '!') {
				vertex.push_back(make_pair(i, j));
				b[i][j] = vertex.size() - 1;
			}
		}
	}

	int m = vertex.size();

	// ������(�ſ�, ��)���� ���� ���� ���ϴ��� Ȯ��
	vector< vector<bool> > a(m, vector<bool>(m, false));

	for (int i = 0; i < vertex.size(); i++) {
		for (int k = 0; k < 4; k++) {
			int y = vertex[i].first + dy[k];
			int x = vertex[i].second + dx[k];

			while (x >= 0 && y >= 0 && x < n && y < n) {

				// i�������� k�������� ���̻� ���� ����� �� ����
				if (arr[y][x] == '*') break;
				
				if (arr[y][x] == '#' || arr[y][x] == '!') {
					// i��° ������ i��°���� k �������� ������ (y, x)��ǥ�� ���� ���Ѵ�.
					// (y, x)��ǥ�� �� ��° �������� ���� b�� ����Ǿ� ����
					a[i][b[y][x]] = true;
				}

				y += dy[k];
				x += dx[k];
			}
		}
	}


	queue<int> Q;

	// start ���� dist[i]�������� �� �� ������ �̵�Ƚ��. ��, ��ġ�� �ſ��� �ּ� ������ �ȴ�. 
	// ���� end ������ ���̱� ������ 1�� ������Ѵ�.
	vector<int> dist(m, -1);
	
	Q.push(start);
	dist[start] = 0;

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		// now�� m���� ���� �߿��� ���� ���� ���ϴ��� Ȯ��
		for (int i = 0; i < m; i++) {
			// now ������ i ������ ���� ���� ���ϴ� ���, i������ �ſ��� ��ġ
			if (a[now][i] && dist[i] == -1) {
				dist[i] = dist[now] + 1;
				Q.push(i);
			}
		}
	}

	//
	cout << dist[end]-1 << endl;
	return 0;
}