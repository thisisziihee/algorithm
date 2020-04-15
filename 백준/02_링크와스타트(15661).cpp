#include<bits/stdc++.h>
using namespace std;

int n;
vector< vector<int> > arr;
vector<int> start;
vector<int> link;

int ans = 2147000000;

// arr[index] 사람이 start 팀으로 갈건지 link 팀으로 갈건지 결정
void solution(int index) {
	if (index == n) {
		if (start.size() == 0 || link.size() == 0) return;
		else{
			int start_power = 0;
			int link_power = 0;

			for (int i = 0; i < start.size(); i++) {
				for (int j = 0; j < start.size(); j++) {
					if (i == j) continue;
					start_power += arr[start[i]][start[j]];
				}
			}

			for (int i = 0; i < link.size(); i++) {
				for (int j = 0; j < link.size(); j++) {
					if (i == j) continue;
					link_power += arr[link[i]][link[j]];
				}
			}
			
			ans = min(ans, abs(start_power - link_power));

		}
		return;
	}

	start.push_back(index);
	solution(index + 1);
	start.pop_back();

	link.push_back(index);
	solution(index + 1);
	link.pop_back();
}

int main() {
	cin >> n;

	arr = vector< vector<int> >(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solution(0);
	cout << ans << endl;
}