// 가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을 출력하는 프로그램을 작성하세요.

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, minn = 2147000000;
vector<pair <int, int> > map[21];
int check[21];

void dfs(int v, int sum) {
	if (v == n) {
		minn = (sum < minn ? sum : minn);
	}
	else {
		for (int i = 0; i < map[v].size(); i++) {
			if (check[map[v][i].first] == 0) {

				check[map[v][i].first] = 1;
				dfs(map[v][i].first, sum + map[v][i].second);
				check[map[v][i].first] = 0;
			}
		}
	}
}

int main() {
	int m, i, start, end, val;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &start, &end, &val);
		map[start].push_back(make_pair(end, val));
	}
	check[1] = 1;
	dfs(1, 0);
	printf("%d", minn);
}
