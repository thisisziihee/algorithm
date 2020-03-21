/*
수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 2, 50, 60} 이고, 합은 113이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	// dp[i] : 1번째부터 i번째 배열 위치에서 얻을 수 있는 가장 큰 증가 부분 수열 합
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