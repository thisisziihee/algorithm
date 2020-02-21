/*
임의의 N에 대하여 N!은 소수들의 곱으로 표현하는 방법이 있다. 
예를 들면 825는 (0 1 2 0 1)로 표현이 가능한데, 이는 2는 없고 3은 1번, 5는 2번, 7은 없고, 11은 1번의 곱이라는 의미이다. 
101보다 작은 임의의 N에 대하여 N 팩토리얼을 이와 같은 표기법으로 변환하는 프로그램을 작성해보자. 
*/

#include<stdio.h>
#include<vector>

int main() {
	int n, i, j, temp;
	scanf("%d", &n);
	
	std::vector<int> check(n + 1);

		// 소인수분해 사용
		// 굳이 팩토리얼을 다 계산한 이후에 소인수분해 하지말고 for문 돌려서 소인수분해
	for (i = 2; i <= n; i++) {
		temp = i;
		j = 2;
		while (true) {
			if (temp%j == 0) {
				temp = temp / j;
				check[j]++;
			}
			else j++;
			
			if (temp == 1)break;
		}
	}
	printf("%d! = ", n);
	for (i = 2; i <= n; i++) {
		if (check[i] > 0) {
			printf("%d ", check[i]);
		}
	}
}

