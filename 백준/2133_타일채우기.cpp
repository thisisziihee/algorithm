/*
3��N ũ���� ���� 2��1, 1��2 ũ���� Ÿ�Ϸ� ä��� ����� ���� ���غ���.

�Է�
ù° �ٿ� N(1 �� N �� 30)�� �־�����.

���
ù° �ٿ� ����� ���� ����Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2 == 1) cout << 0 << endl;
	else {
		vector<int> dp(n, 0);
		dp[1] = 3;
		dp[2] = 11;
		for (int i = 3; i <= n / 2; i++) {
			dp[i] = dp[i - 1] * 3 + 2;
			for (int j = i - 2; j > 0; j--) {
				dp[i] += 2 * dp[j];
			}
		}
		cout << dp[n / 2] << endl;
	}
	return 0;
}