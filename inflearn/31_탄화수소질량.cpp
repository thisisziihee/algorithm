// 탄화수소식이 주어지면 해당 화합물의 질량을 구하는 프로그램을 작성하세요.

#include<stdio.h>

int main() {
	char ch[100];
	// pos : H 위치
	int c = 0, h = 0, pos, i;
	scanf("%s", &ch);

	if (ch[1] == 'H') {
		c = 1; pos = 1;
	}
	else {
		for (i = 1; ch[i] != 'H'; i++) {
			c = c * 10 + (ch[i] - 48);
		}
		pos = i;
	}

	if (ch[pos + 1] == '\0') h = 1;
	else {
		for (i = pos + 1; ch[i] != '\0'; i++) {
			h = h * 10 + (ch[i] - 48);
		}
	}
	printf("%d\n", c * 12 + h);
}
