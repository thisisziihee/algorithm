//SEND+MORE=MONEY 라는 유명한 복면산이 있습니다. 이 복면산을 구하는 프로그램을 작성하세요.

#include <stdio.h>
using namespace std;
int a[10], check[10];

int send() {
	return a[6] * 1000 + a[1] * 100 + a[3] * 10 + a[0];
}

int more() {
	return a[2] * 1000 + a[4] * 100 + a[5] * 10 + a[1];
}

int money() {
	return a[2] * 10000 + a[4] * 1000 + a[3] * 100 + a[1] * 10 + a[7];
}


void DFS(int L) {
	if (L == 8) {
		if (send() + more() == money()) {
			if (a[2] == 0 || a[6] == 0) return;
			printf("   %d %d %d %d \n", a[6], a[1], a[3], a[0]);
			printf("+  %d %d %d %d \n", a[2], a[4], a[5], a[1]);
			printf("--------------\n");
			printf(" %d %d %d %d %d \n", a[2], a[4], a[3], a[1], a[7]);
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (check[i] == 0) {
				a[L] = i;
				check[i] = 1;
				DFS(L + 1);
				check[i] = 0;
			}
		}
	}
}

int main() {
	DFS(0);
	return 0;
}