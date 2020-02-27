// 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 모든 경로의 가지 수를 출력하는 프로그램을 작성하세요.

#include<stdio.h>
#include <vector>

int n;
std::vector<int> map[21];
int check[21];
int cnt = 0;

void dfs(int v) {
	if (v == n) {
		cnt++;
	}
	else {
		// map[v][i]의 값은 v와 연결되어 있기 때문에 check 값만 확인하면 됨
		for (int i = 0; i < map[v].size(); i++) {
			if (check[map[v][i]] == 0) {
				check[map[v][i]] = 1;
				dfs(map[v][i]);
				check[map[v][i]] = 0;
			}
		}
	}
}

int main() {
	int m, i, j, start, end;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &start, &end);
		map[start].push_back(end);
	}
	check[1] = 1;
	dfs(1);
	printf("%d", cnt);
}
