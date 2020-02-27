/*
▣ 입력설명 : 첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 
그 다음부터 M줄에 걸쳐 연결정보와 거리비용이 주어진다.
▣ 출력설명 : 인접행렬을 출력하세요.
*/
#include<stdio.h>
int map[21][21];
int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);

	int start, end, val;
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &start, &end, &val);
		map[start][end] = val;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}