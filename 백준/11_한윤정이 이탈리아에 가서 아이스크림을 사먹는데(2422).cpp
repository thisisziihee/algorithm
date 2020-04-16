#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	bool ic[201][201];

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ic[a][b] = true;
		ic[b][a] = true;
	}


	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (ic[i][j]) continue;
			for (int k = j+1; k <= n; k++) {
				if (ic[i][k] || ic[j][k]) continue;
				ans += 1;
			}
		}
	}
	cout << ans << endl;
}