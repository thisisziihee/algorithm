// �������� : i , i+1�� ���ؼ� �� ���������� ū ���� �����Ѵ�.
#include<stdio.h>

int main() {
	int num[101], n, i, j, temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (num[j] > num[j + 1]) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
}