/*
현수는 네트워크 선을 1m, 2m 의 길이를 갖는 선으로 자르려고 합니다.
예를 들어 4m의 네트워크 선이 주어진다면
1m + 1m + 1m + 1m
2m + 1m + 1m
1m + 2m + 1m
1m + 1m + 2m
2m + 2m
의 다섯가지 방법을 생각할 수 있습니다. 자르는 위치가 다르면 다른 경우로 본다.
그렇다면 네트워크 선의 길이가 Nm라면 몇 가지의 자르는 방법을 생각할 수 있나요?
*/

#include <bits/stdc++.h>
using namespace std;
int dy[101] = { 0 };

int get_dy(int n) {
	if (n == 1 || n == 2) return dy[n];
	if (dy[n] > 0) return dy[n];
	else return dy[n] = get_dy(n - 1) + get_dy(n - 2);
}


int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	dy[1] = 1;
	dy[2] = 2;
	
	get_dy(n);

	cout << dy[n] << endl;
}