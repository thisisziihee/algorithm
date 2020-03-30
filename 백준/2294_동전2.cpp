/*
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 
그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.
사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 
동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

출력
첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.
*/

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &arr, int k) {

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == k) return 1;
	}

	vector<int> dpp(k + 1, 2147000000);
	dpp[0] = 1;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = arr[i]; j <= k; j++) {
			int temp = j / arr[i];
			if (j%arr[i] == 0) dpp[j] = min(dpp[j], temp);
			else {
				for (int k = temp; k >= 0; k--) {
					if (dpp[j - (k*arr[i])] == 2147000000) continue;
					dpp[j] = min(dpp[j], dpp[j - (k*arr[i])] + k);
				}
			}
		}
	}

	for (int i = 0; i <= k; i++) cout << dpp[i] << " ";
	cout << endl << endl;

	if (dpp[k] == 2147000000)return -1;
	else return dpp[k];
}


int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> coins(n, 0);
	for (int i = 0; i < n; i++) cin >> coins[i];

	cout << solution(coins, k) << endl;
	return 0;
}