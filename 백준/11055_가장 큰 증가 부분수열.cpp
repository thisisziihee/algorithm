/*
���� A�� �־����� ��, �� ������ ���� �κ� ���� �߿��� ���� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ���� A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �� ��쿡 ���� ���� ū ���� �κ� ������ A = {1, 2, 50, 60} �̰�, ���� 113�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� ���� ū ���� �κ� ������ ���� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	// dp[i] : 1��°���� i��° �迭 ��ġ���� ���� �� �ִ� ���� ū ���� �κ� ���� ��
	vector<int> dp(n + 1, 0);

	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] ) {
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
		if (dp[i] == 0) dp[i] = arr[i];
	}

	cout << *max_element(dp.begin(), dp.end()) << endl; 

	return 0;
}