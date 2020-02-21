/*
N개의 정수가 입력되면 당신은 입력된 값을 정렬해야 한다.음의 정수는 앞쪽에 양의정수는 뒷쪽에 있어야 한다. 또한 양의정수와 음의정수의 순서에는 변함이 없어야 한다.
▣ 입력설명 : 첫 번째 줄에 정수 N(5<=N<=100)이 주어지고, 그 다음 줄부터 음수를 포함한 정수가 주어진다. 숫자 0은 입력되지 않는다.
▣ 출력설명 : 정렬된 결과를 출력한다.
*/

#include<stdio.h>



int main() {
	int n, num[101], i, j, minustemp, temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	// 방법 1 
	/*int minusIdx = 0;
	for (i = 0; i < n; i++) {
		if (num[i] < 0) {
			minustemp = num[i];
			for (j = i-1; j >= minusIdx; j--) {
				temp = j+1;
				num[temp] = num[j];
			}
			num[minusIdx] = minustemp;
			minusIdx++;
		}
	}*/


	// 방법 2 
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (num[j] > 0 && num[j + 1] < 0) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}


	for (i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
}