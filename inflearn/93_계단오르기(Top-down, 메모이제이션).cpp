/*
ö���� ����� ���� �� �� ���� �� ��� �Ǵ� �� ��ܾ� �ö󰣴�. ���� �� 4����� �����ٸ� �� ����� ���� 5�����̴�.
�׷��ٸ� �� N����� �� ö�����ö� �� �ִ� ����� ���� �� �����ΰ�?
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