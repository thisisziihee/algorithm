/*
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 30, 50} �̰�, ���̴� 4�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, n;
	cin >> n;
	
	vector<int> arr(n, 0);
	for (i = 0; i < n; i++) cin >> arr[i];

	vector<int> dy(n, 0);

	
	for (i = 0; i < n; i++) {
		dy[i] = 1;
		for (j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dy[i] = max(dy[i], dy[j] + 1);
			}
		}
	}

	cout << *max_element(dy.begin(), dy.end()) << endl;

	return 0;
}