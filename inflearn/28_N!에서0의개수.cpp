// 자연수 N이 입력되면 N! 값에서 일의 자리부터 연속적으로 ‘0’이 몇 개 있는지 구하는 프로그램을 작성하세요.

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
