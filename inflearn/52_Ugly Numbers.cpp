/*
어떤 수를 소인수분해 했을 때 그 소인수가 2 또는 3 또는 5로만 이루어진 수를 Ugly Number라고 부릅니다. 
Ugly Number를 차례대로 적어보면 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......입니다. 숫자 1은 Ugly Number의 첫 번째 수로 합니다. 
자연수 N이 주어지면 Ugly Number를 차례로 적을 때 N번째 Ugly Number를 구하는 프로그램을 작성하세요.
*/


#include<stdio.h>
int a[1501];

int main() {
	int num, i, min = 2147000000, p2, p3, p5;
	scanf("%d", &num);

	a[1] = 1;
		// p2 : 2를 곱할 포인터, p3 : 3 , p5 : 
	p2 = p3 = p5 = 1;

	for (i = 2; i <= num; i++) {
			// (p2*2, p3*3, p5*5) 세 값 중에 최소값 찾기
		if (a[p2] * 2 < a[p3] * 3) min = a[p2] * 2;
		else min = a[p3] * 3;
		if (a[p5] * 5 < min) min = a[p5] * 5;

			// 세 값 중에 중복되는 값이 있다면 동시에 포인터++;
			// 그러지 않으면 a 배열에 값이 중복되어버림
		if (a[p2] * 2 == min) p2++;
		if (a[p3] * 3 == min) p3++;
		if (a[p5] * 5 == min) p5++;

			// 결국 1을 시작으로 2, 3, 5만 곱하므로 무조건 2 , 3 또는 5를 소인수로 갖는 숫자가 된다.
		a[i] = min;
	}
	printf("%d\n", a[num]);
	return 0;
}