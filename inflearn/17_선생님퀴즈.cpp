#include<stdio.h>
int main() {
	int n, val, ans, i, j, sum;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &val, &ans);
		sum = 0;
		for (j = 1; j <= val; j++) {
			sum += j;
		}
		if (sum == ans)printf("YES\n");
		else printf("NO\n");
	}
}