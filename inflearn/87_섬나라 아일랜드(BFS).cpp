/*
������ ���Ϸ����� ������ �������� ������ �־����ϴ�. �� ���� 1�� ǥ�õǾ� �����¿�� �밢������ ����Ǿ� ������, 0�� �ٴ��Դϴ�. 
������ ���Ϸ��忡 �� ���� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��ϼ���.
*/

#include <stdio.h>
#include <queue>

using namespace std;

int n, map[30][30], cnt = 0;
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

struct Loc {
	int x;
	int y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};

queue<Loc> Q;

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				Q.push(Loc(i, j));
				map[i][j] = 0;
				while (!Q.empty()) {
					Loc tmp = Q.front();
					Q.pop();
					for (int k = 0; k < 8; k++) {
						int xx = tmp.x + dx[k];
						int yy = tmp.y + dy[k];
						if (map[xx][yy] == 1) {
							Q.push(Loc(xx, yy));
							map[xx][yy] = 0;
						}
					}
				}
				cnt += 1;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}