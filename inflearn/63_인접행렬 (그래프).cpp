/*
�� �Է¼��� : ù° �ٿ��� ������ �� N(1<=N<=20)�� ������ �� M�� �־�����. 
�� �������� M�ٿ� ���� ���������� �Ÿ������ �־�����.
�� ��¼��� : ��������� ����ϼ���.
*/
#include<stdio.h>
int map[21][21];
int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);

	int start, end, val;
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &start, &end, &val);
		map[start][end] = val;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}