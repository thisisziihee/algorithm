/*
예를 들어 총 8명의 왕자가 있고, 3을 외친 왕자가 제외된다고 하자. 처음에는 3번 왕자가 3을 외쳐 제외된다. 
이어 6, 1, 5, 2, 8, 4번 왕자가 차례대로 제외되고 마지막까지 남게 된 7번 왕자에게 공주를 구하러갑니다.
N과 K가 주어질 때 공주를 구하러 갈 왕자의 번호를 출력하는 프로그램을 작성하시오.
*/

// 1 ~ (K-1) 까지의 왕자들은 push_back K번째 왕자는 pop. 계속 한 명만 남을 때까지 반복한다.

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, k, i;

	queue<int> Q;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++) {
		Q.push(i);
	}

	while (!Q.empty()) {
			// k-1 명을 지날 때 까지는 push
		for (i = 1; i < k; i++) {
			Q.push(Q.front());
			Q.pop();
		}

			// k번째 왕자는 pop으로 없애준다.
		Q.pop();

		if (Q.size() == 1) {
			printf("%d", Q.front());
			Q.pop();
		}
	}
	return 0;
}