#include<bits/stdc++.h>
using namespace std;

int arr[5][8];
bool visited[5] = { false };

void print() {
	cout << " ========================== " << endl;
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "============================" << endl;
}

void rotate(int wheel, int turn) {
	if (turn == 1) {
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

void solution(int wheel, int turn) {
	visited[wheel] = true;

	int prev = wheel - 1;
	int next = wheel + 1;

	if (prev >= 0 && !visited[prev]) {
		if (arr[prev][2] != arr[wheel][6]) {
			solution(prev, turn * -1);
		}
	}
	
	if (next < 5 && !visited[next]) {
		if (arr[next][6] != arr[wheel][2]) {
			solution(next, turn * -1);
		}
	}

	rotate(wheel, turn);
	print();
}


int main() {
	string temp;
	for (int i = 1; i <= 4; i++) {
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			arr[i][j] = temp[j] - 48 ;
		}
	}

	int k, a, b;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		fill(visited, visited + 5, false);
		solution(a, b);
	}

	int ans = 0;

	for (int i = 1; i <= 4; i++) {
		if (arr[i][0] == 1) {
			ans += pow(2, i - 1);
		}
	}
	cout << ans << endl;
}