/*
�ڿ��� N�� �ԷµǸ� 1���� N������ �ڿ����� ���̿� ���� �� �� ���� �� 3�� ������ �� �� �ִ��� ���Ϸ��� �մϴ�.
���� ��� 1���� 15������ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5���� 3�� ������ 2���Դϴ�.
*/
#include <stdio.h>

int main() {
	int n, i, temp, num, threeCnt = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		temp = i;
		while (temp > 0) {
			num = temp % 10;
			temp = temp / 10;
			if (num == 3) threeCnt++;
		}
	}
	printf("%d", threeCnt);
}