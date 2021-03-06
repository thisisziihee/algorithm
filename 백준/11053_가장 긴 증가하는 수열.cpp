/*
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 30, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
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