/*
N개의 자연수로 이루어진 수열이 주어졌을 때, 그 중에서 가장 길게 증가하는 원소들의 집합을 찾는 프로그램을 작성하라.
예를들어, 원소가 2, 7, 5, 8, 6, 4, 7, 12, 3이면 가장 길게 증가하는 원소들을 뽑아내면 
2, 5, 6, 7, 12를 뽑아내어 길이가 5인 최대 부분 증가 수열을 만들 수 있다.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, num;
	cin >> n;
	vector<int> num_arr(n + 1), dy(n + 1);
	// dy_table[i] : 만들고자 하는 증가수열의 마지막 항이 i번째 숫자이면서 가장 긴 길이를 갖는 수열의 길이

	for (int i = 0; i < n; i++) cin >> num_arr[i];
	
	dy[1] = 1;
	int temp;
	// 마지막 항이 num_arr[i]일 때의 최대 부분 증가 수열
	for (int i = 2; i <= n; i++) {
		dy[i] = 1;
		for (int j = i - 1; j > 0; j--) {
			if (num_arr[j] < num_arr[i]) {
				temp = dy[j] + 1;
				dy[i] = (dy[i] > temp ? dy[i] : temp);
			}
		}
	}
	cout << *max_element(dy.begin(), dy.end());
	return 0;
}