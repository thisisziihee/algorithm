#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int q[10];
int front = -1, back = -1;

int check[10];
vector<int> map[10];

int main() {
	int i, start, end;

	for (i = 1; i <= 6; i++) {
		scanf("%d %d", &start, &end);
		map[start].push_back(end);
		map[end].push_back(start);
	}
	q[++back] = 1;
	check[1] = 1;
	int x;

	while (front < back) {
		x = q[++front];
		printf("%d ", x);
		//x와 연결된 노드 enque
		for (i = 0; i < map[x].size(); i++) {
			if (check[map[x][i]] == 0) {
				check[map[x][i]] = 1;
				q[++back] = map[x][i];
			}
		}
	}

}