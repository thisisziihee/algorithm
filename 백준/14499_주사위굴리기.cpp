/*
ũ�Ⱑ N��M�� ������ �����Ѵ�. ������ �������� ����, ������ �����̴�. �� ������ ���� �ֻ����� �ϳ� ������ ������, 
�ֻ����� �������� �Ʒ��� ����. ������ ��ǥ�� (r, c)�� ��Ÿ����, r�� �������κ��� ������ ĭ�� ����, c�� �������κ��� ������ ĭ�� �����̴�.

  2
4 1 3
  5
  6

�ֻ����� ���� ���� �� ���� 1�̰�, ������ �ٶ󺸴� ������ 3�� ���·� ������ ������, ������ �ִ� ���� ��ǥ�� (x, y) �̴�. ���� ó���� �ֻ������� ��� �鿡 0�� ������ �ִ�.
������ �� ĭ���� ������ �ϳ��� ������ �ִ�. �ֻ����� ������ ��, �̵��� ĭ�� ���� �ִ� ���� 0�̸�, �ֻ����� �ٴڸ鿡 ���� �ִ� ���� ĭ�� ����ȴ�. 
0�� �ƴ� ��쿡�� ĭ�� ���� �ִ� ���� �ֻ����� �ٴڸ����� ����Ǹ�, ĭ�� ���� �ִ� ���� 0�� �ȴ�.

�ֻ����� ���� ���� ��ǥ�� �̵���Ű�� ����� �־����� ��, �ֻ����� �̵����� �� ���� ��ܿ� ���� �ִ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�ֻ����� ������ �ٱ����� �̵���ų �� ����. ���� �ٱ����� �̵���Ű���� �ϴ� ��쿡�� �ش� ����� �����ؾ� �ϸ�, ��µ� �ϸ� �� �ȴ�.

�Է�
ù° �ٿ� ������ ���� ũ�� N, ���� ũ�� M (1 �� N, M �� 20), �ֻ����� ���� ���� ��ǥ x y(0 �� x �� N-1, 0 �� y �� M-1), �׸��� ����� ���� K (1 �� K �� 1,000)�� �־�����.

��° �ٺ��� N���� �ٿ� ������ ���� �ִ� ���� ���ʺ��� ��������, �� ���� ���ʺ��� ���� ������� �־�����. �ֻ����� ���� ĭ�� ���� �ִ� ���� �׻� 0�̴�. 
������ �� ĭ�� ���� �ִ� ���� 10�� ���� �ʴ� �ڿ��� �Ǵ� 0�̴�.
������ �ٿ��� �̵��ϴ� ����� ������� �־�����. ������ 1, ������ 2, ������ 3, ������ 4�� �־�����.

���
�̵��� ������ �ֻ����� �� �鿡 ���� �ִ� ���� ����Ѵ�. ���� �ٱ����� �̵���Ű���� �ϴ� ��쿡�� �ش� ����� �����ؾ� �ϸ�, ��µ� �ϸ� �� �ȴ�.
*/

#include<bits/stdc++.h>
using namespace std;

struct Dice {
	int up, down, front, back, left, right;
	int x, y;
	Dice(int a, int b, int c, int d, int e, int f) {
		up = a;
		down = b;
		front = c;
		back = d;
		left = e;
		right = f;
	}
	void moveDice(int a, int b, int c, int d, int e, int f) {
		up = a;
		down = b;
		front = c;
		back = d;
		left = e;
		right = f;
	}
};

int main() {
	int n, m, xx, yy, k;
	cin >> n >> m >> yy >> xx >> k;

	vector< vector<int> > map(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	vector<int> order(k, 0);
	for (int i = 0; i < k; i++) {
		cin >> order[i];
	}

	Dice D(0, 0, 0, 0, 0, 0);
	D.x = xx;
	D.y = yy;

	int dx[5] = { 0, 1, -1, 0, 0 };
	int dy[5] = { 0, 0, 0, -1, 1 };

	for (int i = 0; i < k; i++) {
		xx = D.x + dx[order[i]];
		yy = D.y + dy[order[i]];
		if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
		else {
			D.x = xx;
			D.y = yy;
			// �ֻ��� ��ġ �ű��
			// up down front back left right
			if (order[i] == 4) D.moveDice(D.back, D.front, D.up, D.down, D.left, D.right);
			else if (order[i] == 3) D.moveDice(D.front, D.back, D.down, D.up, D.left, D.right);
			else if (order[i] == 2) D.moveDice(D.right, D.left, D.front, D.back, D.up, D.down);
			else if (order[i] == 1) D.moveDice(D.left, D.right, D.front, D.back, D.down, D.up);

			if (map[D.y][D.x] == 0) map[D.y][D.x] = D.down;
			else {
				D.down = map[D.y][D.x];
				map[D.y][D.x] = 0;
			}
		}
		cout << D.up << endl;
	}
}