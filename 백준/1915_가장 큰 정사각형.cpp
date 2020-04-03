/*
n��m�� 0, 1�� �� �迭�� �ִ�. �� �迭���� 1�� �� ���� ū ���簢���� ũ�⸦ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
0	1	0	0
0	1	1	1
1	1	1	0
0	0	1	0
���� ���� ���������� ����� 2��2 �迭�� ���� ū ���簢���̴�.

�Է�
ù° �ٿ� n, m(1 �� n, m �� 1,000)�� �־�����. ���� n���� �ٿ��� m���� ���ڷ� �迭�� �־�����.

���
ù° �ٿ� ���� ū ���簢���� ���̸� ����Ѵ�.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector< vector<int> > arr;
vector< vector<int> > dp;

int whoisSmaller(int y, int x) {
	int ans = 2147000000;
	int dx[4] = { -1, 0, -1, 0 };
	int dy[4] = { -1, -1, 0, 0 };
	for (int i = 0; i < 3; i++) {
		int xx, yy;
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
			ans = min(ans, arr[yy][xx]);
		}
	}
	if (ans == 2147000000) ans = 0;
	return ans;
}

int main() {
	cin >> n >> m;
	arr = vector< vector<int> > (n, vector<int>(m, -1));
	string temp;
	int val = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j] - 48;
			if (arr[i][j] == 1) val = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


	dp = vector< vector<int> > (n, vector<int>(m, 0));

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (arr[i][j] != 0) {
				arr[i][j] = whoisSmaller(i, j) + 1;
				val = max(val, arr[i][j]);
			}
		}
	}

	cout << val * val << endl;
}