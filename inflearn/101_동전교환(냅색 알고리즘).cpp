/*
다음과 같이 여러 단위의 동전들이 주어져 있을때 거스름돈을 가장 적은 수의 동전으로 교환해주려면 어떻게 주면 되는가? 각 단위의 동전은 무한정 쓸 수 있다.

▣ 입력설명
첫 번째 줄에는 동전의 종류개수 N(1<=N<=12)이 주어진다. 
두 번째 줄에는 N개의 동전의 종류가 주어지고, 
그 다음줄에 거슬러 줄 금액 M(1<=M<=500)이 주어진다. 각 동전의 종류는 100원을 넘지 않는다.

▣ 출력설명
첫 번째 줄에 거슬러 줄 동전의 최소개수를 출력한다.

3
1 2 5
15
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	int coin;
	cin >> n;

	vector<int> coins(n);

	for (int i = 0; i < n; i++) cin >> coins[i];
	
	cin >> m;

	// dy[j] : j원을 거슬러주는 데에 필요한 동전의 최소 개수
	vector<int> dy(m + 1, 1000);

	// 최솟값을 찾기 위해 dy 배열을 1000으로 초기화하였으므로 dy[0]은 0이어야 한다.
	dy[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= m; j++) {
			dy[j] = min(dy[j], dy[j - coins[i]] + 1);
		}
	}

	cout << dy[m] << endl;
}