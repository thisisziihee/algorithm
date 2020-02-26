/*
N개의 원소로 구성된 자연수 집합이 주어지면, 집합의 원소와 ‘+’, ‘-’ 연산을 사용하여 특정수인 M을 만드는 경우가 몇 가지 있는지 출력하는 프로그램을 작성하세요.
각 원소는 연산에 한 번만 사용합니다. 예를 들어 {2, 4, 6, 8}이 입력되고, M=12이면
2+4+6=12 / 4+8=12 / 6+8-2=12 / 2-4+6+8=12
로 총 4가지의 경우가 있습니다. 만들어지는 경우가 존재하지 않으면 -1를 출력한다.
*/

#include<stdio.h>
int n, m, value[11] = { 0 }, mCnt = 0;
int path[11];

void dfs(int index, int result) {
	if (index == n + 1) {
		if (result == m) { 
			mCnt++;
			// m이 되는 계산 과정 확인
			for (int i = 1; i < index; i++) {
				printf("%d ", path[i]);
			}
			printf("\n");
		}
		return;
	}
	else {
		// - value[index]
		path[index] = value[index];
		dfs(index + 1, result + value[index]);

		// + value[index]
		path[index] = -value[index];
		dfs(index + 1, result - value[index]);

		// 어떤 연산도 안취함
		path[index] = 0;
		dfs(index + 1, result);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &value[i]);
	dfs(1, 0);
	if (mCnt > 0) printf("%d", mCnt);
	else printf("-1");
}