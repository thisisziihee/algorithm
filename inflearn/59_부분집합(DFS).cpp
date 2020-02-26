/*
�ڿ��� N�� �־����� 1���� N������ ���Ҹ� ���� ������ �κ������� ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
��͸� �̿��� ����Ž���� �ϸ�, ����Ʈ�� ������ȸ ������� ����Ѵ�.
*/
#include <stdio.h>
#include <vector>
using namespace std;

int num;
int ch[11] = { 0 };

void dfs(int lv) {
	if (lv == num + 1) {
		for (int i = 1; i <= num; i++) {
			if (ch[i] == 1) {
				printf("%d ", i);
			}
		}
		printf("\n");
		return;
	}
	else {
		ch[lv] = 1;
		dfs(lv + 1);
		ch[lv] = 0;
		dfs(lv+1);
	}
}

int main() {
	scanf("%d", &num);
	dfs(1);
}