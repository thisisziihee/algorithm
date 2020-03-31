/*
���� S�� � �� Sk�� �������� S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN�� �����Ѵٸ�, �� ������ ������� �����̶�� �Ѵ�.

���� ���, {10, 20, 30, 25, 20}�� {10, 20, 30, 40}, {50, 40, 25, 10} �� ������� ����������,  {1, 2, 3, 2, 1, 2, 3, 2, 1}�� {10, 20, 30, 40, 20, 30} �� ������� ������ �ƴϴ�.

���� A�� �־����� ��, �� ������ �κ� ���� �� ������� �����̸鼭 ���� �� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� A�� ũ�� N�� �־�����, ��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� N �� 1,000, 1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� �κ� ���� �߿��� ���� �� ������� ������ ���̸� ����Ѵ�.

���� : 10 [1 5 2 1 4 3 4 5 2 1]  -> [1, 2, 3, 4, 5, 2, 1] returns 7;
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<int> incre(n, 0);
	vector<int> decre(n, 0);
	vector<int> temp;
	vector<int> temp_dp;


	for (int i = 0; i < n; i++) {
		// ���� �κ�
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) incre[i] = max(incre[i], incre[j] + 1);
		}
		if (incre[i] == 0) incre[i] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		decre[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				decre[i] = max(decre[i], decre[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, decre[i] + incre[i] - 1);
	}
	cout << ans << endl;
	return 0;
}