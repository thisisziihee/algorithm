// �ڿ��� N�� �ԷµǸ� N! ������ ���� �ڸ����� ���������� ��0���� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��ϼ���.

#include <stdio.h>
#include <vector>

int main() {
	int n, i, j, cnt1 = 0, cnt2 = 0, temp;
	scanf("%d", &n);

	for (i = 2; i <= n; i++) {
		temp = i;
		j = 2;
		while (temp != 1) {
			if (temp%j == 0) {
				temp = temp / j;
				if (j == 2)cnt1++;
				else if (j == 5)cnt2++;
			}
			else j++;
		}
	}
	printf("%d", (cnt1 > cnt2 ? cnt2 : cnt1));
	return 0;
}
