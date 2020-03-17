/*
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 
각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1. 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
2. N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
3. i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 
집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력 : 첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector< vector<int> > house(n+1, vector<int>(3, 0));
	vector< vector<int> > pay(n+1, vector<int>(3, 0));

	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			// i번째 집을 빨강 초록 파랑으로 칠하는 각각의 비용
			cin >> house[i][j];
		}
	}
	house[0][0] = house[0][1] = house[0][2] = 0;
	pay[0][0] = pay[0][1] = pay[0][2] = 0;

	cout << " ====================" << endl;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			cout << house[i][j] << " ";
		}
		cout << endl;
	}


	for (i = 1; i <= n; i++) {
		// pay[i][j]를 만들기 위해서 pay[i-1][j::] , house[i][j] 비교 
		for (j = 0; j < 3; j++) {
			int minn = 2147000000;
			for (k = 0; k < 3; k++) {
				if (k == j) continue;
				else if (pay[i - 1][k] < minn) minn = pay[i - 1][k];
			}
			pay[i][j] = house[i][j] + minn;
			cout << i << "," << j << " : " << pay[i][j] << endl;
		}
	}


	cout << "=====================" << endl;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			cout << pay[i][j] << " ";
		}
		cout << endl;
	}


	cout << *min_element(pay[n].begin(), pay[n].end()) << endl;
	for (auto i : pay[n]) {
		cout << i << endl;
	}

	return 0;
}