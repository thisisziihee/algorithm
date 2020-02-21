/*
A�� B�� �þ���� ī���� ���ڰ� ������� �־��� ��, ������ ���ڰ� A���� B����, �Ǵ� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�� �Է¼��� : ù ��° �ٿ��� A�� �þ���� ī���� ���ڵ��� ��ĭ�� ���̿� �ΰ� ������� �־�����. 
			  �� ��° �ٿ��� B�� �þ���� ī���� ���ڵ��� ��ĭ�� ���̿� �ΰ� ������� �־�����.
�� ��¼��� : ù ��° �ٿ��� ������ ���� ��, A�� B�� ���� �� ������ ������� ��ĭ�� ���̿� �ΰ� ����Ѵ�. 
			  �� ��° �ٿ��� �̱� ����� A���� B���� �����ؼ�, �̱� ����� ���� A �Ǵ� B�� ����Ѵ�. ���� ���� ��쿡�� ���� D�� ����Ѵ�.
*/

#include<stdio.h>

int main() {
	int playerA[11], playerB[11];
	int i;
	for (i = 0; i < 10; i++) { scanf("%d", &playerA[i]); }
	for (i = 0; i < 10; i++) { scanf("%d", &playerB[i]); }

	char lastWinner = 'D';
	int aScore = 0, bScore = 0;
	for (i = 0; i < 10; i++) {
		if (playerA[i] > playerB[i]) {
			aScore += 3;
			lastWinner = 'A';
		}
		else if (playerA[i] < playerB[i]) {
			bScore += 3;
			lastWinner = 'B';
		}
		else if (playerA[i] == playerB[i]) {
			aScore += 1;
			bScore += 1;
		}
	}

	printf("%d %d\n", aScore, bScore);
	if (aScore > bScore) printf("A");
	else if (aScore < bScore) printf("B");
	else if (aScore == bScore) printf("%c", lastWinner);
}