/*
N개의 정수로 이루어진 수열에 대해 서로 인접해 있는 두 수의 차가 1에서 N-1까지의 값을
모두 가지면 그 수열을 유쾌한 점퍼(jolly jumper)라고 부른다.
*/
#include<stdio.h>
#include<vector>
#include<algorithm>

int main() {
	int n, i, value, ans = 0;
	scanf("%d", &n);
	std::vector<int> checkArr(n);

	int pre, now, temp;
	scanf("%d", &pre);
	for (i = 1; i < n; i++) {
		scanf("%d", &now);
		temp = abs(pre - now);
			// temp 값의 범위를 먼저 확인해야함
		if (temp > 0 && temp < n && checkArr[temp] == 0) {
			checkArr[temp] = 1;
		}
		else if (checkArr[temp] > 0 || temp >= n) {
			printf("NO");
			return 0;
		}
		pre = now;
	}
	printf("YES");
	return 0;
}