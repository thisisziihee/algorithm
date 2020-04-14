#include<bits/stdc++.h>
using namespace std;

int n;
vector< vector<int> > arr;
vector<bool> visited;

void rotate(int wheel, int dir) {
	if (dir == 1) {
		int temp = arr[wheel][7];
		for (int i = 7; i > 0; i--) {
			arr[wheel][i] = arr[wheel][i - 1];
		}
		arr[wheel][0] = temp;
	}
	else {
		int temp = arr[wheel][0];
		for (int i = 0; i < 7; i++) {
			arr[wheel][i] = arr[wheel][i + 1];
		}
		arr[wheel][7] = temp;
	}
}

void solution(int wheel, int dir) {
	visited[wheel] = true;

	int prev = wheel - 1;
	int next = wheel + 1;

	if (prev >= 0 && !visited[prev]) {
		if (arr[prev][2] != arr[wheel][6]) solution(prev, dir*-1);
	}
	if (next < n && !visited[next]) {
		if (arr[wheel][2] != arr[next][6]) solution(next, dir*-1);
	}
	rotate(wheel, dir);
}

int main() {
	cin >> n;
	arr = vector< vector<int> >(n, vector<int>(8, 0));
	visited = vector<bool>(n, false);

	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}

	int k, num, dir;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> num >> dir;
		visited = vector<bool>(n, false);
		solution(num - 1, dir);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i][0] == 1) {
			ans += 1;
		}
	}
	cout << ans << endl;
}