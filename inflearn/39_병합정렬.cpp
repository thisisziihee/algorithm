/*
������������ ������ �� �� �迭�� �־����� �� �迭�� ������������ ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
������ 3��. �ϳ��� �ϼ��迭 �ΰ��� �Է� �迭. �Էµ� �� �迭�� �����ͷ� ���� ��
*/
#include <stdio.h>
#include <vector>
int main() {
	int n, m, i;
	int a[101], b[101], c[201];
	int aPointer = 1, bPointer = 1, cPointer = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (i = 1; i <= m; i++) scanf("%d", &b[i]);

	while (aPointer <= n && bPointer <= m) {
		if (a[aPointer] < b[bPointer]) {
			c[cPointer++] = a[aPointer++];
		}
		else {
			c[cPointer++] = b[bPointer++];
		}
	}

	while (aPointer <= n) {
		c[cPointer++] = a[aPointer++];
	}
	while (bPointer <= m) {
		c[cPointer++] = b[bPointer++];
	}

	for (i = 1; i < cPointer; i++) {
		printf("%d ", c[i]);
	}
}