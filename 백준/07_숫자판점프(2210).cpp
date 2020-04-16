#include<bits/stdc++.h>
using namespace std;

int arr[5][5];
int visited[5][5];
set<string> ans;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void solution(int cnt, int y, int x, string num) {
	if (cnt == 6) {
		ans.insert(num);
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (xx >= 0 && yy >= 0 && yy < 5 && xx < 5) {
				solution(cnt + 1, yy, xx, to_string(arr[yy][xx]) + num);
			}
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visited[i][j] = 1;
			solution(1, i, j, to_string(arr[i][j]));
			visited[i][j] = 0;
		}
	}
	
	cout << ans.size() << endl;
}