//�ڿ��� N�� R�� �־����� ���� �ٸ� N���� �ڿ��� �� R���� �̾� �Ϸķ� �����ϴ� ���α׷��� �ۼ��ϼ���.

#include<stdio.h>
#include<queue>
#include <vector>

int a[20], res[20], check[20];
int n, r, cnt = 0;

int DFS(int v) {
	if (v == r) {
		for (int j = 0; j < v; j++) {
			printf("%d ", res[j]);
		}
		cnt++;
		puts("");
	}
	else {
		// v��° �� ���ϱ�
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				res[v] = a[i];
				check[i] = 1;
				DFS(v + 1);
				check[i] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	DFS(0);
	printf("%d\n", cnt);
}