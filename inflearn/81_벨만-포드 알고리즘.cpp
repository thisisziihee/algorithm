/*
N개의 도시가 주어지고, 각 도시들을 연결하는 도로와 해당 도로를 통행하는 비용이 주어질 때
한 도시에서 다른 도시로 이동하는데 쓰이는 비용의 최소값을 구하는 프로그램을 작성하세요.
*/

#include<stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int dist[101];

struct Edge {
	int s;
	int e;
	int val;
	Edge(int a, int b, int c) {
		s = a;
		e = b;
		val = c;
	}
};

int main() {
	vector <Edge> Ed;
	int i, n, m, a, b, c, j, s, e;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));
	}
	for (i = 1; i <= n; i++) dist[i] = 2147000000;
	scanf("%d %d", &s, &e);
	dist[s] = 0;

	// i:간선 개수 -> 한 번에 갈 수 있는 정점들. 
	// 2,3..개의 간선을 거쳐서 갈 수 있는 정점들 탐색
	for (i = 1; i < n; i++) {
		for (j = 0; j < Ed.size(); j++) {
			int u = Ed[j].s;
			int v = Ed[j].e;
			int w = Ed[j].val;
			if (dist[u] != 2147000000 && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
			}
		}
	}
	// 간선 n개를 거쳐서 도착하는지 확인 -> 음의 사이클 확인
	for (j = 0; j < Ed.size(); j++) {
		int u = Ed[j].s;
		int v = Ed[j].e;
		int w = Ed[j].val;
		if (dist[u] != 2147000000 && dist[u] + w < dist[v]) {
			printf("-1\n");
			exit(0);
		}
	}
	printf("%d\n", dist[e]);
	return 0;
}
