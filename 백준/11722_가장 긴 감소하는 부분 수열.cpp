/*
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ���� A = {10, 30, 10, 20, 20, 10} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {30, 20, 10}  �̰�, ���̴� 3�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];


	vector<int> dp(n, 0);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] == 0) dp[i] = 1;
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;
}