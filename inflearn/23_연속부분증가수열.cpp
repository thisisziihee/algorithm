/*
N���� ���ڰ� ������ ������ �־����ϴ�. �� ���� �� ���������� �����ϴ� �κ� ������ �ִ���̸� ���Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
*/
#include<stdio.h>

int main() {
	int n, i, cnt = 1, max = 1, pre, now;
	scanf("%d", &n);

		// �� ó�� ���� ���� �Է¹ް� �� ���� �Է��� ���� ������ ������ ���� ��.
	scanf("%d", &pre);
	for (i = 1; i < n; i++) { 
		scanf("%d", &now); 
		if (pre <= now) {
			cnt++;
			if (max < cnt) max = cnt;
		}
		else cnt = 1;
		pre = now;
	}
	printf("%d", max);
}