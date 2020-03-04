/*
��������� ��� ���ø� ���� �����ϸ鼭 �ּ��� ��������� �鵵�� ���θ� �����ϰ� ������ ���δ� ����Ϸ��� �Ѵ�.

�� �Է¼���
ù° �ٿ� ������ ���� V(1��V��100)�� ������ ���� E(1��E��1,000)�� �־�����. ���� E���� �ٿ��� �� ���ο� ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����. 
�̴� A�� ���ÿ� B�� ���ð� ��������� C�� ���η� ����Ǿ� �ִٴ� �ǹ��̴�. C�� 1,000,000�� ���� �ʴ� �ڿ����̴�.
�� ��¼��� : ��� ���ø� �����ϸ鼭 ��� �ּҺ���� ����Ѵ�.
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

		// Ed ���� ������ �����ڿ� ���ؼ� ����ġ ���� ���� ���ĵ�
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