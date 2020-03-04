/*
�Ʒ��� ����ġ ����׷������� 1�� �������� ��� ���������� �ּ� �Ÿ������ ����ϴ� ���α׷��� �ۼ��ϼ���. (��ΰ� ������ Impossible�� ����Ѵ�)
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
			// �湮 �������鼭 ���̰� ���� ��� 
			// min : �ּҰ��� ���� ���� ��ȣ
			if (check[j] == 0 && dist[j] < dist[min]) {
				min = j;
			}
		}
		
		check[min] = 1;
			// min ���� ��ȣ�� ���� ���� ����� ���� Ž��
			// ����� ��� v �� �Ÿ����� (dist[min]������ �Ÿ� + min -> v ������ �Ÿ�) ��  �� ���� �� ����
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