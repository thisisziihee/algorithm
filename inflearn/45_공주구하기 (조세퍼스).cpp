/*
예를 들어 총 8명의 왕자가 있고, 3을 외친 왕자가 제외된다고 하자. 처음에는 3번 왕자가 3을 외쳐 제외된다. 
이어 6, 1, 5, 2, 8, 4번 왕자가 차례대로 제외되고 마지막까지 남게 된 7번 왕자에게 공주를 구하러갑니다.
N과 K가 주어질 때 공주를 구하러 갈 왕자의 번호를 출력하는 프로그램을 작성하시오.
▣ 입력설명 : 첫 줄에 자연수 N(5<=N<=1,000)과 K(2<=K<=9)가 주어진다.
▣ 출력설명 : 첫 줄에 마지막 남은 왕자의 번호를 출력합니다.
*/

#include <stdio.h>
#include <vector>

int main() {
	int n, k, i, outPrince = 0, pos = 0, cnt = 0;
	scanf("%d %d", &n, &k);

	std::vector<int> prince(n+1);

	while (true) {
		pos++;
		if (pos > n) pos = 1;
		if (prince[pos] == 0) {
			cnt++;
			if (cnt == k) {
				prince[pos] = 1;
				outPrince++;
				cnt = 0;
			}
		}
		if (outPrince == n - 1) {
			break;
		}
	}
	for (i = 1; i <= n; i++) {
		if (prince[i] == 0) { printf("%d", i); break; }
	}
}