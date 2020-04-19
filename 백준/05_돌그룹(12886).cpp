#include <iostream>

using namespace std;

int sum;
bool visited[1501][1501];

void solution(int x, int y) {
	// y와 x 값에 대해서 연산을 이미 진행했던 경우에, 또 진행하면 같은 값이 나와서 무한 루프에 빠질 수 있음
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

	// 전체 합이 3으로 나눠지지 않는다면, 어떤 연산을 취해도 나누어질 수 없음
	if (sum % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}

	solution(x, y);
	if (visited[sum / 3][sum / 3]) cout << 1 << endl;
	else cout << 0 << endl;
}