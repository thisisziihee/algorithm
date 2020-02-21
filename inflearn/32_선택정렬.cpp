// 선택정렬 : 이중for문 돌면서 가장 작은 숫자부터 정렬


#include<stdio.h>

int main() {
	int numArr[100], i, idx, j, temp, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &numArr[i]);
	}

	for (i = 0; i < n - 1; i++) {
		idx = i;
		for (j = i + 1; j < n; j++) {
			if (numArr[idx] > numArr[j]) idx = j;
		}
		temp = numArr[idx];
		numArr[idx] = numArr[i];
		numArr[i] = temp;
	}

	for (i = 0; i < n; i++) {
		printf("%d ", numArr[i]);
	}
}