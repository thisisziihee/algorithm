/*
N���� ������ �̷���� ������ ���� ���� ������ �ִ� �� ���� ���� 1���� N-1������ ����
��� ������ �� ������ ������ ����(jolly jumper)��� �θ���.
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
			// temp ���� ������ ���� Ȯ���ؾ���
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