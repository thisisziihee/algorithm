/*
두 사람의 각 회의 가위, 바위, 보 정보가 주어지면 각 회를 누가 이겼는지 출력하는 프로그램을 작성하세요.
▣ 입력설명 : 첫 번째 줄에 게임 횟수인 자연수 N(1<=N<=100)이 주어집니다.
			  두 번째 줄에는 A가 낸 가위, 바위, 보 정보가 N개 주어집니다.
			  세 번째 줄에는 B가 낸 가위, 바위, 보 정보가 N개 주어집니다.
▣ 출력설명 : 각 줄에 각 회의 승자를 출력합니다. 비겼을 경우는 D를 출력합니다.
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