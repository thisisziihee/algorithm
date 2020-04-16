#include<iostream>

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;

	// dp[i] ������ ���� �� �ִ��� Ȯ���ϴ� �迭
	bool dp[360] = { false };
	dp[0] = true;

	int arr[10];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[arr[i]] = true;
	}

	// ���� �� �ִ� �� �� i, j�� �̿��ؼ� ���ο� ���� �����.
	for (int i = 0; i < 360; i++) {
		if (!dp[i]) continue;
		for (int j = 0; j < 360; j++) {
			if (!dp[j]) continue;
			dp[(i + j) % 360] = true;
			dp[(i - j + 360) % 360] = true;
		}
	}

	int num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (dp[num]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}