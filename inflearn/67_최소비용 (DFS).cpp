/*
가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>
#include <vector>
using namespace std;

int n;
int map[21][21];
int check[21];
int sum = 0, min = 2147000000;


void dfs(int v) {
	if (v == n) {
		min = (sum < min ? sum : min);
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (map[v][i] > 0 && check[i] == 0) {
				check[i] = 1;
				sum += map[v][i];
				dfs(i);
				check[i] = 0;
				sum -= map[v][i];
			}
		}
	}
}

int main() {
	int m, i, start, end, val;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &start, &end, &val);
		map[start][end] = val;
	}
	check[1] = 1;
	dfs(1);
	printf("%d", min);
}
