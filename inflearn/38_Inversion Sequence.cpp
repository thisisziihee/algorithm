/*
n과 1부터 n까지의 수를 사용하여 이루어진 수열의 inversion sequence가 주어졌을 때, 원래의 수열을 출력하는 프로그램을 작성하세요.
1부터 n까지 각각의 수 앞에 놓여 있는 자신보다 큰 수들의 개수를 수열로 표현한 것을 Inversion Sequence
 */

#include<stdio.h>

int main() {
	int n, i, j, idx;
	int is[101] = { 0 };
	int os[101] = { 0 };
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &is[i]);

	// 이 문제의 핵심은 n 부터 내림차순으로 처리해나가는 것
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
