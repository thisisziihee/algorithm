/*
���� ������ N*N �����ǿ� �־����ϴ�. �� ���ڿ��� �� ������ ���̰� �����ֽ��ϴ�. 
�� �������� ���� �� �ڽ��� �����¿� ���ں��� ū ���ڴ� ���츮 �����Դϴ�. 
���츮 ������ �� ���ִ� �� �˾Ƴ��� ���α׷��� �ۼ��ϼ���.
*/

#include<stdio.h>
int n, mount[51][51];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	int i, j, k, peekCnt = 0, flag;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &mount[j][i]);
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			flag = 0;
			for (k = 0; k < 4; k++) {
				if (mount[j][i] <= mount[j + dx[k]][i + dy[k]]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) peekCnt++;
		}
	}

	printf("%d", peekCnt);
}
