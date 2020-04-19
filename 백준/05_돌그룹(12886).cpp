#include <iostream>

using namespace std;

int sum;
bool visited[1501][1501];

void solution(int x, int y) {
	// y�� x ���� ���ؼ� ������ �̹� �����ߴ� ��쿡, �� �����ϸ� ���� ���� ���ͼ� ���� ������ ���� �� ����
	if (visited[x][y]) return;

	visited[x][y] = true;
	visited[y][x] = true;

	int arr[3] = { x, y, sum - (x + y) };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i] < arr[j]) {
				int val1, val2;
				val1 = arr[i] + arr[i];
				val2 = arr[j] - arr[i];
				solution(val1, val2);
			}
		}
	}
}

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	sum = x + y + z;

	// ��ü ���� 3���� �������� �ʴ´ٸ�, � ������ ���ص� �������� �� ����
	if (sum % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}

	solution(x, y);
	if (visited[sum / 3][sum / 3]) cout << 1 << endl;
	else cout << 0 << endl;
}