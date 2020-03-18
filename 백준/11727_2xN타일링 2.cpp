/*
2×n 직사각형을 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)
출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> dy(n + 1, 0);
	dy[1] = 1;
	dy[2] = 3;
	for (int i = 3; i <= n; i++) {
		dy[i] = (dy[i - 2] * 2 + dy[i - 1])%10007;
	}
	cout << dy[n] << endl;
	return 0;
}