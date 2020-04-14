#include<bits/stdc++.h>
using namespace std;

int N, L;

bool isitOK(vector<int> &load) {
	vector<bool> visited(N, false);

	for (int i = 1; i < N; i++) {
		if (load[i] != load[i - 1]) {
			int diff = load[i] - load[i - 1];

			// 두 칸의 높이 차이가 1이 넘는 경우
			if (abs(diff) != 1) return false;

			if (load[i] > load[i - 1]) {
				for (int j = 1; j <= L; j++) {
					
					// L개가 연속되지 않을 경우
					if (i - j < 0) return false;

					// L개의 칸들이 높이가 서로 다른 경우
					if (load[i - 1] != load[i - j]) return false;

					// 이미 경사로가 놓아진 경우
					if (visited[i - j]) return false;

					// 경사로 놓을 조건을 모두 만족한다면 경사로 설치
					visited[i - j] = true;
				}
			}

			else {
				for (int j = 0; j < L; j++) {
					// L개가 연속되지 않는 경우
					if (i + j >= N) return false;

					// L개의 칸들이 높이가 서로 다른 경우
					if (load[i] != load[i + j]) return false;

					// 이미 경사로가 설치되어있는 경우
					if (visited[i + j]) return false;

					// 모든 조건을 만족한다면 경사로 설치
					visited[i + j] = true;
				}
			}
		}
	}
	return true;
}

int main() {
	cin >> N >> L;
	
	vector< vector<int> > arr(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;

	// 열 검사
	for (int i = 0; i < N; i++) {
		vector<int> d;
		for (int j = 0; j < N; j++) {
			d.push_back(arr[i][j]);
		}
		if (isitOK(d)) ans += 1;
	}

	// 행 검사
	for (int i = 0; i < N; i++) {
		vector<int> d;
		for (int j = 0; j < N; j++) {
			d.push_back(arr[j][i]);
		}
		if (isitOK(d)) ans += 1;
	}

	cout << ans << endl;
}