#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> arr;
bool dp[20 * 100000 + 10] = { false };

void solution(int index, int sum) {
	if (index == n) {
		dp[sum] = true;
		return;
	}
	solution(index + 1, sum + arr[index]);
	solution(index + 1, sum);
}

int main() {
	cin >> n;
	arr = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[arr[i]] = true;
	}
	solution(0, 0);

	int ans = 1;
	while (dp[ans]) {
		ans += 1;
	}
	cout << ans << endl;
}