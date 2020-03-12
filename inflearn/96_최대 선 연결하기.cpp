/*
������ ��ȣ�� �������� ��ȣ�� �ִ� �׸����� ���� ��ȣ���� ������ �����Ϸ��� �մϴ�.
���ʹ�ȣ�� ������ ���������� ���ʷ� 1���� N���� ������������ �����Ǿ� �ֽ��ϴ�. �������� ��ȣ ������ ������ �Ʒ� ������ �־�����,
���� ���̰�ġ�� �ʰ� �ִ� �� ���� ���� ������ �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

// LIS ����. �ִ� ���� ���� ���� ���� ������ �迭 ������ �ִ� �κ� ���� ������ ���̿� ����.

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> right_arr(n + 1), dy(n + 1);

	for (int i = 1; i <= n; i++) cin >> right_arr[i];

	dy[1] = 1;
	int maxx;
	for (int i = 2; i <= n; i++) {
		maxx = 0;
		for (int j = i - 1; j > 0; j--) {
			if (right_arr[i] > right_arr[j] && maxx < dy[j]) {
				maxx = dy[j];
			}
		}
		dy[i] = maxx + 1;
	}
	cout << *max_element(dy.begin(), dy.end()) << endl;
	return 0;
}