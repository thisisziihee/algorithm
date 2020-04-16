#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> arr;

int solution(vector<int> &a) {
	if (a.size() == 2)return 0;
	int ans = 0;
	for (int i = 1; i < a.size() - 1; i++) {
		int energy = a[i - 1] * a[i + 1];
		vector<int> b(a);
		b.erase(b.begin() + i);
		energy += solution(b);
		if (ans < energy) ans = energy;
	}
	return ans;
}

int main() {
	cin >> n;
	arr = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << solution(arr) << endl;
}