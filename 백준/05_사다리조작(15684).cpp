#include<bits/stdc++.h>
using namespace std;

int n, m, h;
int arr[100][100];

// i번째 사다리 타기를 진행해서 나오는 결과값 반환
int draw_straws(int i) {
	int now = 1;
	while (now <= h) {
		if (arr[now][i] == 1) i += 1;
		else if (arr[now][i] == 2) i -= 1;
		now += 1;
	}
	return i;
}


// 현재 arr에서 사다리타기를 진행하면 세로선 i가 i에 도착하는지 확인
bool check_i_to_i() {
	for (int i = 1; i <= n; i++) {
		int temp = draw_straws(i);
		if (temp != i) return false;
	}
	return true;
}


int main() {
	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		// (a,b)에는 1, (a, b+1)에는 2를 저장해서 서로 이어진 가로선임을 나타냄
		// 특정 위치에 도달했을 때, 좌표값이 1이면 오른쪽으로 이동, 2이면 왼쪽으로 이동
		arr[a][b] = 1;
		arr[a][b + 1] = 2;
	}

	// 가로선이 될 수 있는 후보 모두 넣음
	vector< pair<int, int> > aa;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n - 1; j++) {
			if (arr[i][j] == 0 && arr[i][j + 1] == 0) {
				aa.emplace_back(i, j);
			}
		}
	}

	// 이미 문제의 조건을 만족하는 경우
	if (check_i_to_i()) {
		cout << 0 << endl;
		return 0;
	}

	int ans = -1;

	for (int i = 0; i < aa.size(); i++) {
		int a1 = aa[i].first;
		int b1 = aa[i].second;
		if (arr[a1][b1] != 0 || arr[a1][b1 + 1] != 0) continue;
		arr[a1][b1] = 1;
		arr[a1][b1 + 1] = 2;
		if (check_i_to_i()) {
			// 최소 가로선으로 만족하는 경우가 있을 수 있으므로 바로 끝내면 안됨
			if (ans == -1 || ans > 1)
				ans = 1;
		}
		for (int j = i + 1; j < aa.size(); j++) {
			int a2 = aa[j].first;
			int b2 = aa[j].second;
			if (arr[a2][b2] != 0 || arr[a2][b2 + 1] != 0) continue;
			arr[a2][b2] = 1;
			arr[a2][b2 + 1] = 2;
			if (check_i_to_i()) {
				if (ans == -1 || ans > 2) {
					ans = 2;
				}
			}
			for (int k = j + 1; k < aa.size(); k++) {
				int a3 = aa[k].first;
				int b3 = aa[k].second;
				if (arr[a3][b3] != 0 || arr[a3][b3 + 1] != 0) continue;
				arr[a3][b3] = 1;
				arr[a3][b3 + 1] = 2;
				if (check_i_to_i()) {
					if (ans == -1 || ans > 3) {
						ans = 3;
					}
				}
				arr[a3][b3] = 0;
				arr[a3][b3 + 1] = 0;
			}
			arr[a2][b2] = 0;
			arr[a2][b2 + 1] = 0;
		}
		arr[a1][b1] = 0;
		arr[a1][b1 + 1] = 0;
	}
	cout << ans << endl;

	return 0;
}