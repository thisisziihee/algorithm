/*
현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다. 
현수의 위치와 송아지의 위치가 직선상의 좌표 점으로 주어지면 현수는 현재 위치에서 송아지의 위치까지 다음과같은 방법으로 이동한다.
현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 앞으로 1, 뒤로 1, 앞으로 5를 이동할 수있다. 
최소 몇 번의 점프로 현수가 송아지의 위치까지 갈 수 있는지 구하는 프로그램을 작성하세요.
*/

// 상태 트리 탐색, 한번에 움직일 수 있는 거리만큼 노드 뻗음. 앞으로 1, 뒤로 1 앞으로 5 총 세 가지 방법 있으니까 하나의 정점에서 3개 노드 뻗는다.
// 새로운 정점을 만들 때마다 송아지 위치랑 일치하는지 확인


#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int check[10001];	// 방문 여부도 체크함과 동시에 점프 횟수 카운팅
int dist[3] = { 1, -1, 5 };

int main() {
	// x : queue에서 pop 하는 값 
	int hyunsoo, cow, x, pos, i;
	scanf("%d %d", &hyunsoo, &cow);

	queue<int> Q;
	check[hyunsoo] = 1;
	Q.push(hyunsoo);

	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		for (i = 0; i < 3; i++) {
			if (x + dist[i] == cow) {
					// 출발지점을 1로 시작했으니 check[x+dist[i]] 값에서 1을 뺀다.
				printf("%d\n", check[x]);
				exit(0);
			}
			if (check[x + dist[i]] == 0) {
				check[x + dist[i]] = check[x] + 1;
				Q.push(x + dist[i]);
			}
		}
	}

}