/*
원더랜드는 모든 도시를 서로 연결하면서 최소의 유지비용이 들도록 도로를 선택하고 나머지 도로는 폐쇄하려고 한다.

▣ 입력설명
첫째 줄에 도시의 개수 V(1≤V≤100)와 도로의 개수 E(1≤E≤1,000)가 주어진다. 다음 E개의 줄에는 각 도로에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다.
이는 A번 도시와 B번 도시가 유지비용이 C인 도로로 연결되어 있다는 의미이다. C는 1,000,000을 넘지 않는 자연수이다.
▣ 출력설명 : 모든 도시를 연결하면서 드는 최소비용을 출려한다.
*/

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int check[30];
struct Edge {
	int e;
	int val;
	Edge(int a, int b) {
		e = a;
		val = b;
	}
		// 가중치값에 대해서 오름차순으로 정렬함
	bool operator< (const Edge &b)const {
		return val > b.val;
	}
};


int main() {
	priority_queue<Edge> Q;
	vector<pair<int, int> > map[30];
	int i, n, m, a, b, c, res = 0;
	scanf("%d %d", &n, &m);

		// 간선 정보 무방향 가중치 인접리스트
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	
	Q.push(Edge(1, 0));
	
	while (!Q.empty()) {
		Edge tmp = Q.top();
		Q.pop();
		int v = tmp.e;
		int cost = tmp.val;
			// v 정점이 한번도 방문하지 않은 경우
		if (check[v] == 0) {
			res += cost;
			check[v] = 1;
			for (i = 0; i < map[v].size(); i++) {
				// v정점과 연결된 정점의 정점 번호와 가중치값 push
				Q.push(Edge(map[v][i].first, map[v][i].second));
			}
		}
	}
	printf("%d", res);
	return 0;
}