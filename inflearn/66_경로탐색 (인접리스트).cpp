// ����׷����� �־����� 1�� �������� N�� �������� ���� ��� ����� ���� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

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
		// map[v][i]�� ���� v�� ����Ǿ� �ֱ� ������ check ���� Ȯ���ϸ� ��
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
