/*
N���� ���ҷ� ������ �ڿ��� ������ �־�����, ������ ���ҿ� ��+��, ��-�� ������ ����Ͽ� Ư������ M�� ����� ��찡 �� ���� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
�� ���Ҵ� ���꿡 �� ���� ����մϴ�. ���� ��� {2, 4, 6, 8}�� �Էµǰ�, M=12�̸�
2+4+6=12 / 4+8=12 / 6+8-2=12 / 2-4+6+8=12
�� �� 4������ ��찡 �ֽ��ϴ�. ��������� ��찡 �������� ������ -1�� ����Ѵ�.
*/

#include<stdio.h>
int n, m, value[11] = { 0 }, mCnt = 0;
int path[11];

void dfs(int index, int result) {
	if (index == n + 1) {
		if (result == m) { 
			mCnt++;
			// m�� �Ǵ� ��� ���� Ȯ��
			for (int i = 1; i < index; i++) {
				printf("%d ", path[i]);
			}
			printf("\n");
		}
		return;
	}
	else {
		// - value[index]
		path[index] = value[index];
		dfs(index + 1, result + value[index]);

		// + value[index]
		path[index] = -value[index];
		dfs(index + 1, result - value[index]);

		// � ���굵 ������
		path[index] = 0;
		dfs(index + 1, result);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &value[i]);
	dfs(1, 0);
	if (mCnt > 0) printf("%d", mCnt);
	else printf("-1");
}