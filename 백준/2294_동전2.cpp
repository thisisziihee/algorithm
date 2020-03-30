/*
n���� ������ ������ �ִ�. �� �������� ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. 
�׷��鼭 ������ ������ �ּҰ� �ǵ��� �Ϸ��� �Ѵ�. ������ ������ �� ���� ����� �� �ִ�.
����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.

�Է�
ù° �ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10,000) ���� n���� �ٿ��� ������ ������ ��ġ�� �־�����. 
������ ��ġ�� 100,000���� �۰ų� ���� �ڿ����̴�. ��ġ�� ���� ������ ���� �� �־��� ���� �ִ�.

���
ù° �ٿ� ����� ������ �ּ� ������ ����Ѵ�. �Ұ����� ��쿡�� -1�� ����Ѵ�.
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