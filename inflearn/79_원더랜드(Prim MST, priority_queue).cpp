/*
��������� ��� ���ø� ���� �����ϸ鼭 �ּ��� ��������� �鵵�� ���θ� �����ϰ� ������ ���δ� ����Ϸ��� �Ѵ�.

�� �Է¼���
ù° �ٿ� ������ ���� V(1��V��100)�� ������ ���� E(1��E��1,000)�� �־�����. ���� E���� �ٿ��� �� ���ο� ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����.
�̴� A�� ���ÿ� B�� ���ð� ��������� C�� ���η� ����Ǿ� �ִٴ� �ǹ��̴�. C�� 1,000,000�� ���� �ʴ� �ڿ����̴�.
�� ��¼��� : ��� ���ø� �����ϸ鼭 ��� �ּҺ���� ����Ѵ�.
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
		// ����ġ���� ���ؼ� ������������ ������
	bool operator< (const Edge &b)const {
		return val > b.val;
	}
};


int main() {
	priority_queue<Edge> Q;
	vector<pair<int, int> > map[30];
	int i, n, m, a, b, c, res = 0;
	scanf("%d %d", &n, &m);

		// ���� ���� ������ ����ġ ��������Ʈ
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
			// v ������ �ѹ��� �湮���� ���� ���
		if (check[v] == 0) {
			res += cost;
			check[v] = 1;
			for (i = 0; i < map[v].size(); i++) {
				// v������ ����� ������ ���� ��ȣ�� ����ġ�� push
				Q.push(Edge(map[v][i].first, map[v][i].second));
			}
		}
	}
	printf("%d", res);
	return 0;
}