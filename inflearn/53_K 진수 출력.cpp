// 10���� N�� �ԷµǸ� K������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���. ���� �ڷᱸ���� ����Ͻñ� �ٶ��ϴ�.

#include<stdio.h>
int stack[100], top = -1;

void push(int value) {
	stack[++top] = value;
}

int pop() {
	return stack[top--];
}

int main() {
	int n, k, temp;
	scanf("%d %d", &n, &k);

	while (n > 0) {
		temp = n % k;
		n = n / k;
		push(temp);
	}

	char str[20] = "0123456789ABCDEF";
	while (top > -1) {
			// 16���������� 10, 11, 12, 13, 14, 15�� ���� ���ڰ� ����ϵ���
		printf("%c", str[pop()]);
	}

}