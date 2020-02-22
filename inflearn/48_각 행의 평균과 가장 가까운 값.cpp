/*
9 �� 9 �����ǿ� ������ 81���� �ڿ����� �־��� ��, �� ���� ����� ���ϰ�,�� ��հ� ���� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���. 
����� �Ҽ��� ù ° �ڸ����� �ݿø��մϴ�. ��հ� ����� ���� �� ���̸� �� �� ū ���� ����ϼ���.
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