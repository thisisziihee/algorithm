 /*
 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 모든 경로의 가지 수를 출력하는 프로그램을 작성하세요. 
▣ 입력설명 : 첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연결정보가 주어진다.
▣ 출력설명 : 총 가지수를 출력한다
 */

#include<stdio.h>
int map[21][21];	// 그래프
int check[21];		// 해당 정점을 방문했는지 여부
int cnt = 0, n;		// 총 가지 수, 정점 개수

void dfs(int v) {
	if (v == n) {
		//탈출조건
		cnt++;
	}
	else {
		// 갈 수 있는 정점 찾아야 함
		for (int i = 1; i <= n; i++) {
			// v와 연결되어 있으며 한번도 방문하지 않은 정점
			if (i != v && check[i] == 0 && map[v][i] == 1) {
				check[i] = 1;
				dfs(i);
				check[i] = 0;
			}
		}
	}
}

int main() {
	int m, i, j, start, end;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &start, &end);
		map[start][end] = 1;
	}
	check[1] = 1;
	dfs(1);
	printf("%d", cnt);
}