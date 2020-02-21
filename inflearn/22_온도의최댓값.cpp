/*
매일 측정한 온도가 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰값을 계산하는 프로그램을 작성하시오.
*/

#include<stdio.h>
#include<vector>
int main() {
	int n, k, i;
	scanf("%d %d", &n, &k);
	std::vector <int> a(n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int max; int sum = 0;
	for (i = 0; i < k; i++) { sum += a[i]; }
	max = sum;

		// [i-k] 값을 빼고 [i]값을 더해서 k개 개수 유지
		// 이중 for문 없이 시간복잡도 n으로 해결할 수 있다.
	for (i = k; i < n; i++) {
		sum = sum + (a[i] - a[i-k] );
		max = (sum > max ? sum : max);
	}
	printf("%d", max);
}