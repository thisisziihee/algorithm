/*
�ڿ��� N�� ���� K�� �־����� �� ���� ��� (N K)�� 10,007�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� N �� 1,000, 0 �� K �� N)

���
 (N K)�� 10,007�� ���� �������� ����Ѵ�.
*/

#include <bits/stdc++.h>
using namespace std;

vector< vector<int> >dp;

int solution(int n, int k) {
	if (k == 0 || n == k) return 1;
	if (dp[n][k] != 0) {
		return dp[n][k] % 10007;
	}
	else {
		return dp[n][k] = (solution(n - 1, k) + solution(n - 1, k - 1)) % 10007;
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	dp = vector< vector<int> >(n + 1, vector<int>(n + 1, 0));
	cout << solution(n, k) << endl;
	return 0;
}