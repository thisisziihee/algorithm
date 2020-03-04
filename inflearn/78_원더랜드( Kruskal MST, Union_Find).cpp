/*
원더랜드는 모든 도시를 서로 연결하면서 최소의 유지비용이 들도록 도로를 선택하고 나머지 도로는 폐쇄하려고 한다.

▣ 입력설명
첫째 줄에 도시의 개수 V(1≤V≤100)와 도로의 개수 E(1≤E≤1,000)가 주어진다. 다음 E개의 줄에는 각 도로에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 
이는 A번 도시와 B번 도시가 유지비용이 C인 도로로 연결되어 있다는 의미이다. C는 1,000,000을 넘지 않는 자연수이다.
▣ 출력설명 : 모든 도시를 연결하면서 드는 최소비용을 출려한다.
*/

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int unf[10001];

struct Edge {
	int v1, v2, val;
	Edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		val = c;
	}
	bool operator<(Edge &b) {
		return val < b.val;
	}
};

int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main() {
	vector<Edge> Ed;
	int i, m, n, a, b, c, cnt = 0, res = 0;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		unf[i] = i;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));
	}

		// Ed 에서 정의한 연산자에 의해서 가중치 값에 따라 정렬됨
	sort(Ed.begin(), Ed.end());

	for (i = 0; i < m; i++) {
		int fa = Find(Ed[i].v1);
		int fb = Find(Ed[i].v2);
		if (fa != fb) {
			res += Ed[i].val;
			Union(Ed[i].v1, Ed[i].v2);
		}
	}
	printf("%d", res);
}