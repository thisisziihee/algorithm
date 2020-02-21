/*
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자 중 3의 개수가 몇 개 있는지 구하려고 합니다.
예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로 3의 개수는 2개입니다.
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