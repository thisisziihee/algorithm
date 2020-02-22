/*
9 × 9 격자판에 쓰여진 81개의 자연수가 주어질 때, 각 행의 평균을 구하고,그 평균과 가장 가까운 값을 출력하는 프로그램을 작성하세요. 
평균은 소수점 첫 째 자리에서 반올림합니다. 평균과 가까운 값이 두 개이면 그 중 큰 값을 출력하세요.
*/
#include <stdio.h>
#include <algorithm>

int main() {
	int num[10][10];

	int i, j, sum, avg, res;
	int minGap = 2147000000, temp;

	for (i = 1; i <= 9; i++) {
		sum = 0;
		for (j = 1; j <= 9; j++) {
			scanf("%d", &num[i][j]);
			sum += num[i][j];
		}
		avg = (sum / 9.0) + 0.5;
		printf("%d ", avg);


		minGap = 2147000000;
		for (j = 1; j <= 9; j++) {
			temp = abs(num[i][j] - avg);
			if (temp < minGap) {
				minGap = temp;
				res = num[i][j];
			}
			else if (temp == minGap) {
				if (num[i][j] > res) {
					res = num[i][j];
				}
			}
		}
		printf("%d\n", res);
	}
}