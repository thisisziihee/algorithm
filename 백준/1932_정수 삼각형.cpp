/*
		7
	  3   8
	8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.
맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 
아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력 : 첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

출력 : 첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	vector< vector<int> > triangle;
	vector< vector<int> > dy;

	vector<int> temp;
	int i, j;
	for (i = 1; i <= n; i++) {
		temp = vector<int>(i, 0);
		dy.push_back(temp);
		temp.clear();
		while (true) {
			cin >> j;
			temp.push_back(j);
			if (temp.size() == i) {
				triangle.push_back(temp);
				break;
			}
		}
	}
	dy[0][0] = triangle[0][0];

	int maxx = 0;
	for (i = 1; i < triangle.size(); i++) {
		for (j = 0; j < triangle[i].size(); j++) {
			if (j >= 1 && j < triangle[i - 1].size()) {
				dy[i][j] = max(dy[i - 1][j - 1], dy[i - 1][j]) + triangle[i][j];
			}
			else if (j == dy[i - 1].size() && j >= 1) {
				dy[i][j] = dy[i - 1][j - 1] + triangle[i][j];
			}
			else if( j < 1 && j < triangle[i - 1].size() ){
				dy[i][j] = dy[i - 1][j] + triangle[i][j];
			}
			if (maxx < dy[i][j]) maxx = dy[i][j];
		}
	}

	cout << maxx << endl;
	return 0;
}