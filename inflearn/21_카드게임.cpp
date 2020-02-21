/*
A와 B가 늘어놓은 카드의 숫자가 순서대로 주어질 때, 게임의 승자가 A인지 B인지, 또는 비겼는지 결정하는 프로그램을 작성하시오.
▣ 입력설명 : 첫 번째 줄에는 A가 늘어놓은 카드의 숫자들이 빈칸을 사이에 두고 순서대로 주어진다. 
			  두 번째 줄에는 B가 늘어놓은 카드의 숫자들이 빈칸을 사이에 두고 순서대로 주어진다.
▣ 출력설명 : 첫 번째 줄에는 게임이 끝난 후, A와 B가 받은 총 승점을 순서대로 빈칸을 사이에 두고 출력한다. 
			  두 번째 줄에는 이긴 사람이 A인지 B인지 결정해서, 이긴 사람을 문자 A 또는 B로 출력한다. 만약 비기는 경우에는 문자 D를 출력한다.
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