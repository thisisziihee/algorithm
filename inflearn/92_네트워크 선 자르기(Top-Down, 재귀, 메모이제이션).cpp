/*
������ ��Ʈ��ũ ���� 1m, 2m �� ���̸� ���� ������ �ڸ����� �մϴ�.
���� ��� 4m�� ��Ʈ��ũ ���� �־����ٸ�
1m + 1m + 1m + 1m
2m + 1m + 1m
1m + 2m + 1m
1m + 1m + 2m
2m + 2m
�� �ټ����� ����� ������ �� �ֽ��ϴ�. �ڸ��� ��ġ�� �ٸ��� �ٸ� ���� ����.
�׷��ٸ� ��Ʈ��ũ ���� ���̰� Nm��� �� ������ �ڸ��� ����� ������ �� �ֳ���?
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