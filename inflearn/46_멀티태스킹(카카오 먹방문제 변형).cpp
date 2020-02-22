/*
1) 컴퓨터는 1번 작업부터 순서대로 1초씩 작업을 한다. 즉 각 작업을 1초만 작업하고 다음 작업을 하는 식이다.
2) 마지막 번호의 작업을 1초 했으면 다시 1번 작업으로 가서 다시 1초씩 후속 처리를 한다.
3) 처리가 끝난 작업은 작업 스케쥴에서 사라지고 새로운 작업은 들어오지 않는다.

그런데 현수의 컴퓨터가 일을 시작한 지 K초 후에 정전이 되어 컴퓨터가 일시적으로 멈추었다. 
전기가 들어오고 나서 현수의 컴퓨터가 몇 번 작업부터 다시 시작해야 하는지 알아내는프로그램을 작성하세요.

▣ 입력설명 : 첫 번째 줄에 작업의 개수 N(1<=N<=2,000)이 주어지고 그 다음 N줄에 걸쳐 각 작업을 처리하는데 걸리는 시간이 초단위로 주어진다. 
			  한 작업을 처리하는데 필요한 시간은 1,000를 넘지 않는다. 마지막 줄에 정전이 발생한 시간 K(1<=K<=2,000,000)가 주어진다.
▣ 출력설명 : 첫 번째 줄에 몇 번 작업부터 다시 시작해야 하는지 작업 번호를 출력한다. 만약 더 이상 처리할 작업이 없다면 -1를 출력한다.
*/

#include<stdio.h>

int main() {
	int n, work[2001], blackout = 0, i, total = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) { 
		scanf("%d", &work[i]); 
		total += work[i]; 
	
	}
	scanf("%d", &blackout);
	int pos = 0, timeCnt = 0;

	if (total <= blackout) {
		printf("-1");
		return 0;
	}

	while (true) {
		pos++;
		if (pos > n) pos = 1;
		if (work[pos] > 0) {
			work[pos]--;
			timeCnt++;
		}
		if (timeCnt == blackout) {
			break;
		}
	}
	

	while (true) {
		pos++;
		if (pos > n)pos = 1;
		if (work[pos] > 0) {
			printf("%d", pos);
			break;
		}
	}
}