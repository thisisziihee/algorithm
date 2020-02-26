/*
자연수 N이 주어지면 1부터 N까지의 원소를 갖는 집합의 부분집합을 모두 출력하는 프로그램을 작성하세요.
재귀를 이용한 완전탐색을 하며, 이진트리 전위순회 방식으로 출력한다.
*/
#include <stdio.h>
#include <vector>
using namespace std;

int num;
int ch[11] = { 0 };

void dfs(int lv) {
	if (lv == num + 1) {
		for (int i = 1; i <= num; i++) {
			if (ch[i] == 1) {
				printf("%d ", i);
			}
		}
		printf("\n");
		return;
	}
	else {
		ch[lv] = 1;
		dfs(lv + 1);
		ch[lv] = 0;
		dfs(lv+1);
	}
}

int main() {
	scanf("%d", &num);
	dfs(1);
}