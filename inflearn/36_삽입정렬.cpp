// 삽입 정렬 : i는 0이 아니라 1부터 시작. 0~i범위 내에서 a[i]가 들어갈 알맞은 위치에 삽입
#include<stdio.h>

int main() {
	int n, num[101], i, j, temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &num[i]);

	for (i = 1; i < n; i++) {
		temp = num[i];
		for (j = i - 1; j >= 0; j--) {
			if (num[j] > temp) {
					// temp보다 큰 수는 오른쪽으로 밀려남.
				num[j + 1] = num[j];
			}
				// temp 보다 큰 수가 없으니까 j+1 위치에 temp 삽입
				// j+1에 있는 값은 j+2 으로 옮겨졌거나, temp가 i자리에 삽입됨
			else break;
		}
		num[j + 1] = temp;
	}

	for (i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
}