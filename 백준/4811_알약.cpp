#include <iostream>
#include <cstring>

using namespace std;

/*
문제
70세 박종수 할아버지는 매일 매일 약 반알을 먹는다. 손녀 선영이는 종수 할아버지에게 약이 N개 담긴 병을 선물로 주었다.
첫째 날에 종수는 병에서 약 하나를 꺼낸다. 그 다음, 그 약을 반으로 쪼개서 한 조각은 먹고, 다른 조각은 다시 병에 넣는다.
다음 날부터 종수는 병에서 약을 하나 꺼낸다. (약은 한 조각 전체 일 수도 있고, 쪼갠 반 조각 일 수도 있다) 
반 조각이라면 그 약을 먹고, 아니라면 반을 쪼개서 한 조각을 먹고, 다른 조각은 다시 병에 넣는다.
종수는 손녀에게 한 조각을 꺼낸 날에는 W를, 반 조각을 꺼낸 날에는 H 보낸다. 손녀는 할아버지에게 받은 문자를 종이에 기록해 놓는다. 
총 2N일이 지나면 길이가 2N인 문자열이 만들어지게 된다. 이때, 가능한 서로 다른 문자열의 개수는 총 몇 개일까?

입력
입력은 최대 1000개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄이며, 병에 들어있는 약의 개수 N ≤ 30 가 주어진다.
입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서 가능한 문자열의 개수를 출력한다.
*/

long long dp[31][31];

long long solution(int full, int half) {
	// 1. 알약 full, half 개의 알약으로 먹을 수 있는 방법의 수가 이미 계산된 경우
	if (dp[full][half] != -1) return dp[full][half];

	// 2. 알약 full이 없으므로 반 조각 하나 먹음
	if (full == 0) return 1;

	// 3. 알약 반조각 짜리는 없으므로, 한 조각을 반으로 쪼개 먹음
	if (half == 0) return dp[full][half] = solution(full - 1, half + 1);

	// 4. 알약 한 조각 짜리를 쪼개 먹는 경우 + 반 조각짜리 하나를 먹는 경우
	return dp[full][half] = solution(full - 1, half + 1) + solution(full, half - 1);
}

int main() {
	memset(dp, -1, sizeof(dp));

	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		// 알약 n 조각(반조각 아님)이 주어진 경우, 몇 가지 방법으로 먹을 수 있는가
		cout << solution(n, 0) << '\n';
	}
}