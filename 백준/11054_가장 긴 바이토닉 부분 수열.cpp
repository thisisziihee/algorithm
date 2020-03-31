/*
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

예제 : 10 [1 5 2 1 4 3 4 5 2 1]  -> [1, 2, 3, 4, 5, 2, 1] returns 7;
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
		// 증가 부분
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