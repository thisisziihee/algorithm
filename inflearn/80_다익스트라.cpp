/*
아래의 가중치 방향그래프에서 1번 정점에서 모든 정점으로의 최소 거리비용을 출력하는 프로그램을 작성하세요. (경로가 없으면 Impossible를 출력한다)
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

#define x first
#define y second
using namespace std;
int check[30], dist[30];
vector< pair<int, int> > map[30];

int main() {
	int n, m, i, j, a, b, c, min;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
	}

	for (i = 0; i <= n; i++) dist[i] = 2147000000;

	dist[1] = 0;

	for (i = 1; i <= n; i++) {
		min = 0;
		for (j = 1; j <= n; j++) {
			// 방문 안했으면서 길이가 작은 경우 
			// min : 최소값을 갖는 정점 번호
			if (check[j] == 0 && dist[j] < dist[min]) {
				min = j;
			}
		}
		
		check[min] = 1;
			// min 정점 번호를 갖는 노드와 연결된 노드들 탐색
			// 연결된 노드 v 의 거리값과 (dist[min]까지의 거리 + min -> v 까지의 거리) 중  더 작은 값 선택
		for (j = 0; j < map[min].size(); j++) {
			int v = map[min][j].x;
			int cost = map[min][j].y;
			if (dist[v] > dist[min] + cost) {
				dist[v] = dist[min] + cost;
			}
		}
	}
	for (i = 2; i <= n; i++) {
		if (dist[i] != 2147000000) printf("%d : %d\n", i, dist[i]);
		else printf("%d : impossible\n", i);
	}
}