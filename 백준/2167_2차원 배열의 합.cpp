/*
2���� �迭�� �־����� �� (i, j) ��ġ���� (x, y) ��ġ������ ����Ǿ� �ִ� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �迭�� (i, j) ��ġ�� i�� j���� ��Ÿ����.

�Է�
ù° �ٿ� �迭�� ũ�� N, M(1 �� N, M �� 300)�� �־�����. 
���� N���� �ٿ��� M���� ������ �迭�� �־�����. �迭�� ���ԵǾ� �ִ� ���� ������ 10,000���� �۰ų� ���� �����̴�. 
�� ���� �ٿ��� ���� ���� �κ��� ���� K(1 �� K �� 10,000)�� �־�����. ���� K���� �ٿ��� �� ���� ������ i, j, x, y�� �־�����(i �� x, j �� y).

���
K���� �ٿ� ������� �迭�� ���� ����Ѵ�. �迭�� ���� 32bit-int ������ �ʰ����� �ʴ´�.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k, x, y, i, j;
	cin >> n >> m;

	int a, b;
	
	vector< vector<int> > board(n+1, vector<int>(m+1, 0));
	for (a = 1; a <= n; a++) {
		for (b = 1; b <= m; b++) {
			cin >> board[a][b];
		}
	}
	cin >> k;
	for (int a = 0; a < k; a++) {
		cin >> j >> i >> y >> x;
		int sum = 0;
		for (int yy = j; yy <= y; yy++ ) {
			for (int xx = i; xx <= x; xx++) {
				sum += board[yy][xx];
			}
		}
		cout << "<" << sum << ">" << endl;
	}
	return 0;
}