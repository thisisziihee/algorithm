/*
캐시의 크기가 주어지고, 캐시가 비어있는 상태에서 N개의 작업을 CPU가 차례로 처리한다면
N개의 작업을 처리한 후 캐시메모리의 상태를 가장 최근 사용된 작업부터 차례대로 출력하는 프로그램을 작성하세요.
▣ 입력설명 : 첫 번째 줄에 캐시의 크기인 S(3<=S<=10)와 작업의 개수 N(5<=N<=1,000)이 입력된다.
			  두 번째 줄에 N개의 작업번호가 처리순으로 주어진다. 작업번호는 1 ~100 이다.
▣ 출력설명 : 마지막 작업 후 캐시메모리의 상태를 가장 최근 사용된 작업부터 차례로 출력합니다.
*/
#include<stdio.h>
int main() {
	int cacheSize, n, num, i, j, cacheIndex;
	int cache[11] = { 0, };
	scanf("%d %d", &cacheSize, &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);

		cacheIndex = -1;
		for (j = 0; j < cacheSize; j++) {
			if (num == cache[j]) { cacheIndex = j; }
		}

		// 값 추가, 캐시가 꽉차서 맨 끝 숫자 빼고 새로 삽입(캐시 미스)
		if (cacheIndex == -1) {
			for (j = cacheSize -1; j >= 0; j--) {
				cache[j] = cache[j-1];
			}
		}

		// 입력한 작업 번호가 캐시에 있는 경우 
		else if (cacheIndex > -1) {
			for (j = cacheIndex; j >= 0; j--) {
				cache[j] = cache[j-1];
			}
		}
		cache[0] = num;
	}
	for (j = 0; j < cacheSize; j++) {
		printf("%d ", cache[j]);
	}
}