/*
자연수 N과 정수 K가 주어졌을 때 이항 계수 (N K)를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ K ≤ N)

출력
 (N K)를 10,007로 나눈 나머지를 출력한다.
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