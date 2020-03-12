/*
철수는 계단을 오를 때 한 번에 한 계단 또는 두 계단씩 올라간다. 만약 총 4계단을 오른다면 그 방법의 수는 5가지이다.
그렇다면 총 N계단일 때 철수가올라갈 수 있는 방법의 수는 몇 가지인가?
*/

#include <bits/stdc++.h>

using namespace std;

int dy[100];

int get_step(int n) {
	if (dy[n] != 0) return dy[n];
	else return dy[n] = get_step(n - 1) + get_step(n - 2);
}


int main() {
	int n;
	cin >> n;
	dy[1] = 1;
	dy[2] = 2;
	get_step(n);
	cout << dy[n];
}