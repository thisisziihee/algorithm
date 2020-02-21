/*
한 줄에 앉은키 정보가 주어지면 뒷사람 모두의 시야를 가려 영화 시청이 불가능하게 하는 분노유발자가 그 줄에 몇 명이 있는지 구하는 프로그램을 작성하세요
▣ 입력설명 : 첫 줄에 한 줄에 앉은 학생수 N(3<=N<=100)이 주어집니다. 
			  두 번째 줄에 N명의 앉은 키 정보(45이상 100이하)가 앞 자리 학생부터 차례대로 주어집니다.
▣ 출력설명 : 자신의 뒷 사람 모두를 시청방해하는 학생수를 출력합니다.
*/

#include<stdio.h>

int main() {
	int n, studentHeight[101];
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &studentHeight[i]);
	}

	// 가장 뒤에서부터 탐색하면서 max값 갱신 (분노유발자 갱신)
	int max = studentHeight[n];
	int cnt = 0;
	for (int i = n - 1; i > 0; i--) {
		if (max < studentHeight[i]) {
			max = studentHeight[i];
			cnt++;
		}
	}
	printf("%d", cnt);
}