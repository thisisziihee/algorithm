#include<stdio.h>

int main() {
	int scoreArr[101], i, idx, j, temp, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &scoreArr[i]);
	}

	for (i = 0; i < n - 1; i++) {
		idx = i;
		for (j = i + 1; j < n; j++) {
			if (scoreArr[idx] < scoreArr[j]) idx = j;
		}
		temp = scoreArr[idx];
		scoreArr[idx] = scoreArr[i];
		scoreArr[i] = temp;
	}
	int rank = 1;
	for (i = 1; i < n; i++) {
		if (scoreArr[i] != scoreArr[i - 1]) rank++;
		if (rank == 3) {
			printf("%d", scoreArr[i]);
			break;
		}
	}
}