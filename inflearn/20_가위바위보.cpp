/*
�� ����� �� ȸ�� ����, ����, �� ������ �־����� �� ȸ�� ���� �̰���� ����ϴ� ���α׷��� �ۼ��ϼ���.
�� �Է¼��� : ù ��° �ٿ� ���� Ƚ���� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
			  �� ��° �ٿ��� A�� �� ����, ����, �� ������ N�� �־����ϴ�.
			  �� ��° �ٿ��� B�� �� ����, ����, �� ������ N�� �־����ϴ�.
�� ��¼��� : �� �ٿ� �� ȸ�� ���ڸ� ����մϴ�. ����� ���� D�� ����մϴ�.
*/

#include<stdio.h>
#include<math.h>

int main() {
	int playerA[101];
	int playerB[101];
	int n, i;
	scanf("%d", &n);

	for (i = 0; i < n; i++) { scanf("%d", &playerA[i]); }
	for (i = 0; i < n; i++) { scanf("%d", &playerB[i]); }

	int temp;
	for (i = 0; i < n; i++) {
		temp = playerA[i] - playerB[i];
		if (temp == 0) printf("D\n");

		else if (abs(temp) == 1) {
			if (temp > 0) printf("A\n");
			else printf("B\n");
		}

		else if (abs(temp) == 2) {
			if (temp > 0) printf("B\n");
			else printf("A\n");
		}
	}
}