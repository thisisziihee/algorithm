// 10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요. 스택 자료구조를 사용하시기 바랍니다.

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
			// 16진수에서의 10, 11, 12, 13, 14, 15에 대한 문자값 출력하도록
		printf("%c", str[pop()]);
	}

}