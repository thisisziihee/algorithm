/*
�ڿ��� N�� �־����� 7*7 ������ �̷θ� Ż���ϴ� ����� �������� ����ϴ� ���α׷��� �ۼ��ϼ���. 
������� ������ (1, 1) ��ǥ�̰�, Ż�� �������� (7, 7)��ǥ�̴�. �������� 1�� ���̰�, 0�� ����̴�. 
�������� �������� �����¿�θ� �����δ�. �̷ΰ� ������ ���ٸ�
��� 0 0 0 0 0 0
0 1 1 1 1 1 0
0 0 0 1 0 0 0
1 1 0 1 0 1 1
1 1 0 0 0 0 1
1 1 0 1 1 0 0
1 0 0 0 0 0 ����
���� �������� ��������� ���������� �� �� �ִ� ����� ���� 8�����̴�
*/
#include<stdio.h>
int map[8][8];
int check[8][8];
int cnt = 0;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	if (x == 7 && y == 7) {
		cnt++;
	}
	else {
		// ����ġ(x,y)���� ���� �������� �����¿� üũ
		// ���� ��ġ�� �湮���� �ʾƾ� �ϸ�, ���� �ƴϿ�����
		int nextX, nextY;
		for (int i = 0; i < 4; i++) {
			nextX = x + dx[i];
			nextY = y + dy[i];
			if (nextX >= 1 && nextX <= 7 && nextY <= 7 && nextY >= 1 ){
				if (map[nextX][nextY] == 0 && check[nextX][nextY] == 0) {
					check[nextX][nextY] = 1;
					dfs(nextX, nextY);
					check[nextX][nextY] = 0;
				}
			}
		}
	}
}

int main() {
	int i, j;
	for (i = 1; i <= 7; i++) {
		for (j = 1; j <= 7; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	check[1][1] = 1;
	dfs(1, 1);
	printf("%d", cnt);
}