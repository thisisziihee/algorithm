#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[51][51];

vector< pair<int, int> > house;
vector< pair<int, int> > chicken;
int chicken_list[14];

int ans = 2147000000;

void solution(int cnt, int chicken_index) {
	if (chicken_index > chicken.size()) return;
	if (cnt == m) {
		int house_y, house_x, ch_y, ch_x;
		int temp, temp_dis, temp_ans = 0;

		for (int i = 0; i < house.size(); i++) {
			temp = 2147000000;
			house_y = house[i].first;
			house_x = house[i].second;
			for (int j = 0; j < m; j++) {
				ch_y = chicken[chicken_list[j]].first;
				ch_x = chicken[chicken_list[j]].second;
				temp_dis = abs(ch_y - house_y) + abs(ch_x - house_x);
				temp = min(temp, temp_dis);
			}
			temp_ans += temp;
		}
		ans = min(ans, temp_ans);
	}
	else {
		chicken_list[cnt] = chicken_index;
		solution(cnt + 1, chicken_index + 1);
		solution(cnt, chicken_index + 1);
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.emplace_back(i, j);
			else if (arr[i][j] == 2) chicken.emplace_back(i, j);
		}
	}
	solution(0, 0);
	cout << ans << endl;
}