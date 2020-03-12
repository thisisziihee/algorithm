/*
왼쪽의 번호와 오른쪽의 번호가 있는 그림에서 같은 번호끼리 선으로 연결하려고 합니다.
왼쪽번호는 무조건 위에서부터 차례로 1부터 N까지 오름차순으로 나열되어 있습니다. 오른쪽의 번호 정보가 위부터 아래 순서로 주어지면,
서로 선이겹치지 않고 최대 몇 개의 선을 연결할 수 있는지 구하는 프로그램을 작성하시오.
*/

// LIS 응용. 최대 연결 가능 선의 수는 오른쪽 배열 내에서 최대 부분 증가 수열의 길이와 같다.

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> right_arr(n + 1), dy(n + 1);

	for (int i = 1; i <= n; i++) cin >> right_arr[i];

	dy[1] = 1;
	int maxx;
	for (int i = 2; i <= n; i++) {
		maxx = 0;
		for (int j = i - 1; j > 0; j--) {
			if (right_arr[i] > right_arr[j] && maxx < dy[j]) {
				maxx = dy[j];
			}
		}
		dy[i] = maxx + 1;
	}
	cout << *max_element(dy.begin(), dy.end()) << endl;
	return 0;
}