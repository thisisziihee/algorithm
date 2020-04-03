/*
n*n의 크기의 대나무 숲이 있다. 욕심쟁이 판다는 어떤 지역에서 대나무를 먹기 시작한다. 
그리고 그 곳의 대나무를 다 먹어 치우면 상, 하, 좌, 우 중 한 곳으로 이동을 한다. 그리고 또 그곳에서 대나무를 먹는다. 
그런데 단 조건이 있다. 이 판다는 매우 욕심이 많아서 대나무를 먹고 자리를 옮기면 그 옮긴 지역에 그 전 지역보다 대나무가 많이 있어야 한다. 
만약에 그런 지점이 없으면 이 판다는 불만을 가지고 단식 투쟁을 하다가 죽게 된다(-_-)

이 판다의 사육사는 이런 판다를 대나무 숲에 풀어 놓아야 하는데, 어떤 지점에 처음에 풀어 놓아야 하고, 
어떤 곳으로 이동을 시켜야 둘 다 소중한 생명이지만 판다가 최대한 오래 살 수 있는지 고민에 빠져 있다. 우리의 임무는 이 사육사를 도와주는 것이다.
n*n 크기의 대나무 숲이 주어져 있을 때, 이 판다가 최대한 오래 살려면 어떤 경로를 통하여 움직여야 하는지 구하여라.

입력
첫째 줄에 대나무 숲의 크기 n(1 ≤ n ≤ 500)이 주어진다. 그리고 둘째 줄부터 n+1번째 줄까지 대나무 숲의 정보가 주어진다. 
대나무 숲의 정보는 공백을 사이로 두고 각 지역의 대나무의 양이 정수 값으로 주어진다. 대나무의 양은 1,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에는 판다가 최대한 살 수 있는 일수(K)를 출력한다.
*/

#include <bits/stdc++.h>
using namespace std;
int n;
vector< vector<int> > bamboo;
vector< vector<int> > dp;
int ans = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int solution(int y, int x) {
	if (dp[y][x] != 0 ) return dp[y][x];
	else {
		dp[y][x] = 1;
		int xx, yy;
		for (int i = 0; i < 4; i++) {
			xx = x + dx[i];
			yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < n) {
				if (bamboo[yy][xx] > bamboo[y][x]){
					dp[y][x] = max(dp[y][x], solution(yy, xx) + 1);
				}
			}
		}
	}
	return dp[y][x];
}


int main() {
	cin >> n;
	bamboo = vector< vector<int> >(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> bamboo[i][j];
		}
	}


	dp = vector< vector<int> >(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, solution(i, j));
		}
	}
	cout << ans << endl;
}