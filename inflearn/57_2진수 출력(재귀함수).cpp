// 10���� N�� �ԷµǸ� 2������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���. �� ����Լ��� �̿��ؼ� ����ؾ� �մϴ�.

#include<stdio.h>

void recur(int n) {
	if (n == 0) return;
	recur(n / 2);
	printf("%d", n % 2);
}

int main() {
	int n;
	scanf("%d", &n);
	recur(n);
}
