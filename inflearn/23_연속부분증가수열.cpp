/*
N개의 숫자가 나열된 수열이 주어집니다. 이 수열 중 연속적으로 증가하는 부분 수열을 최대길이를 구하여 출력하는 프로그램을 작성하세요.
*/
#include<stdio.h>

int main() {
	int n, i, cnt = 1, max = 1, pre, now;
	scanf("%d", &n);

		// 맨 처음 값은 먼저 입력받고 그 다음 입력이 들어올 때마다 이전의 값과 비교.
	scanf("%d", &pre);
	for (i = 1; i < n; i++) { 
		scanf("%d", &now); 
		if (pre <= now) {
			cnt++;
			if (max < cnt) max = cnt;
		}
		else cnt = 1;
		pre = now;
	}
	printf("%d", max);
}