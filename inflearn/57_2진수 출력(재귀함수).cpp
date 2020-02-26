// 10진수 N이 입력되면 2진수로 변환하여 출력하는 프로그램을 작성하세요. 단 재귀함수를 이용해서 출력해야 합니다.

#include<stdio.h>

void recur(int n) {
	if (n == 0) return;
	recur(n / 2);
	printf("%d", n % 2);
}

int main() {
	int n;
	scanf("%d", &n);
	recur(n);
}
