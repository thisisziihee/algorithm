#include<bits/stdc++.h>
using namespace std;

bool mapp[101][101] = { false };
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };

vector<int> curve(int y, int x, int dir, int gen) {
	// 0세대는 방향이 하나(dir)이므로 g는 1부터 시작한다.
	vector<int> ans = { dir };
	for (int g = 1; g <= gen; g++) {
		vector<int> temp(ans);
		reverse(temp.begin(), temp.end());
		for (int &i : temp) {
			i = (i + 1) % 4;
		}
		ans.insert(ans.end(), temp.begin(), temp.end());
	}
	return ans;
}

int main() {
	int n;
	int y, x, dir, gen;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> y >> x >> dir >> gen;
		vector<int> ans = curve(y, x, dir, gen);
		mapp[x][y] = true;
		for (int k = 0; k < ans.size(); k++) {
			y = y + dy[ans[k]];
			x = x + dx[ans[k]];
			mapp[x][y] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (mapp[i][j] && mapp[i + 1][j] && mapp[i][j + 1] && mapp[i + 1][j + 1]) ans += 1;
		}
	}

	cout << ans << endl;
}