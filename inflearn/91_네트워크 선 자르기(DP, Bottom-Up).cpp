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

int dy[50];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	dy[1] = 1;
	dy[2] = 2;

	for (int i = 3; i <= n; i++) {
		dy[i] = dy[i - 2] + dy[i - 1];
	}
	cout << dy[n] << endl;
}

