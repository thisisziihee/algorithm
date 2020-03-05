//자연수 N과 R이 주어지면 서로 다른 N개의 자연수 중 R개를 뽑아 일렬로 나열하는 프로그램을 작성하세요.

#include<stdio.h>
#include<queue>
#include <vector>

int a[20], res[20], check[20];
int n, r, cnt = 0;

int DFS(int v) {
	if (v == r) {
		for (int j = 0; j < v; j++) {
			printf("%d ", res[j]);
		}
		cnt++;
		puts("");
	}
	else {
		// v번째 수 구하기
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				res[v] = a[i];
				check[i] = 1;
				DFS(v + 1);
				check[i] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	DFS(0);
	printf("%d\n", cnt);
}