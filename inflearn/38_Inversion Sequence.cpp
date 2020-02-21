/*
n�� 1���� n������ ���� ����Ͽ� �̷���� ������ inversion sequence�� �־����� ��, ������ ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
1���� n���� ������ �� �տ� ���� �ִ� �ڽź��� ū ������ ������ ������ ǥ���� ���� Inversion Sequence
 */

#include<stdio.h>

int main() {
	int n, i, j, idx;
	int is[101] = { 0 };
	int os[101] = { 0 };
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &is[i]);

	// �� ������ �ٽ��� n ���� ������������ ó���س����� ��
	for (i = n; i > 0; i--) {
		os[i] = i;

		idx = i;
		for (j = 1; j <= is[i]; j++) {
			os[idx] = os[idx + 1];
			idx++;
		}
		os[idx] = i;
	}
	for (i = 1; i <= n; i++) {
		printf("%d ", os[i]);
	}
}
