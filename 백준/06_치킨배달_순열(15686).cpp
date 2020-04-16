#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m, num;
	cin >> n >> m;

	vector< pair<int, int> > house;
	vector< pair<int, int> > chicken;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (num == 1)house.emplace_back(i, j);
			if (num == 2)chicken.emplace_back(i, j);
		}
	}

	vector<int> order(chicken.size(), 0);
	for (int i = 0; i < m; i++) {
		order[i] = 1;
	}
	sort(order.begin(), order.end());

	int ans = 2147000000;
	do {
		int sum = 0;
		vector<int> dist(house.size(), 2147000000);
		for (int i = 0; i < house.size(); i++) {
			int house_y = house[i].first;
			int house_x = house[i].second;
			for (int j = 0; j < order.size(); j++) {
				if (order[j] == 0) continue;
				int ch_y = chicken[j].first;
				int ch_x = chicken[j].second;
				dist[i] = min(dist[i], abs(house_y - ch_y) + abs(house_x - ch_x));
			}
		}

		int temp_ans = 0;
		for (int i = 0; i < dist.size(); i++) {
			temp_ans += dist[i];
		}
		ans = min(ans, temp_ans);

	} while (next_permutation(order.begin(), order.end()));

	cout << ans << endl;
}