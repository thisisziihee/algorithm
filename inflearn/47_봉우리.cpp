/*
지도 정보가 N*N 격자판에 주어집니다. 각 격자에는 그 지역의 높이가 쓰여있습니다. 
각 격자판의 숫자 중 자신의 상하좌우 숫자보다 큰 숫자는 봉우리 지역입니다. 
봉우리 지역이 몇 개있는 지 알아내는 프로그램을 작성하세요.
*/

#include<stdio.h>
int n, mount[51][51];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	int i, j, k, peekCnt = 0, flag;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &mount[j][i]);
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			flag = 0;
			for (k = 0; k < 4; k++) {
				if (mount[j][i] <= mount[j + dx[k]][i + dy[k]]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) peekCnt++;
		}
	}

	printf("%d", peekCnt);
}
