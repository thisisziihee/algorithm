#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, num, start, end;
	cin >> n;
	vector<int> sum_arr(n+1);

	cin >> sum_arr[1];
	for (int i = 2; i <= n; i++) {
		cin >> num;
		sum_arr[i] = sum_arr[i - 1] + num;
	}
	cin >> start >> end;

	cout << sum_arr[end] - sum_arr[start - 1] << endl;
}