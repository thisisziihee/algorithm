/*
오름차순으로 정렬이 된 두 배열이 주어지면 두 배열을 오름차순으로 합쳐 출력하는 프로그램을 작성하세요.
포인터 3개. 하나는 완성배열 두개는 입력 배열. 입력된 두 배열에 포인터로 값을 비교
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