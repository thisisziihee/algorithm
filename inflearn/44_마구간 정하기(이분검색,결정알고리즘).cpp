/*
N개의 마구간이 수직선상에 있습니다. 각 마구간은 x1, x2, x3, ......, xN의 좌표를 가지며, 마구간간에 좌표가 중복되는 일은 없습니다.
현수는 C마리의 말을 가지고 있는데, 이 말들은 서로 가까이 있는 것을 좋아하지 않습니다.
각 마구간에는 한 마리의 말만 넣을 수 있고, 가장 가까운 두 말의 거리가 최대가 되게 말을 마구간에 배치하고 싶습니다.
C마리의 말을 N개의 마구간에 배치했을 때 가장 가까운 두 말의 거리가 최대가 되는 그 최대값을 출력하는 프로그램을 작성하세요.
▣ 입력설명 : 첫 줄에 자연수 N(3<=N<=200,000)과 C(2<=C<=N)이 공백을 사이에 두고 주어집니다.
				둘째 줄부터 N개의 줄에 걸쳐 마구간의 좌표 xi(0<=xi<=1,000,000,000)가 한 줄에 하나씩 주어집니다.
▣ 출력설명 : 첫 줄에 가장 가까운 두 말의 최대 거리를 출력하세요.
*/

#include <stdio.h>
#include<vector>
#include<algorithm>

int n;
int Count(int len, int magugan[]) {
		// 일단 말을 맨 끝에(인덱스1) 넣는 것이 유리
		// pos : 이전의 말을 넣은 위치. 말 사이의 간격을 비교하기 위한 변수
	int i, cnt = 1, pos = magugan[1];
	for (i = 2; i <= n; i++) {
		if (magugan[i] - pos >= len) {
			cnt++;
			pos = magugan[i];
		}
	}
	return cnt;
}

int main() {
	int c, i;
	int left = 0, right = 0, mid = 0, res = 0;
	scanf("%d %d", &n, &c);
	int *magugan = new int[n + 1];
	for (i = 1; i <= n; i++) scanf("%d", &magugan[i]);
	std::sort(magugan + 1, magugan + n + 1);

		// 두 말의 최대 거리는 마구간 좌표(0 ~ 최대값)으로 최대값은 절대 넘지 못한다.
	right = magugan[n];

	while (left <= right) {
			// 두 말의 거리 값을 정해놓고 말을 배치할 때, 말 사이의 거리가 mid 값이 넘어야한다.
		mid = (left + right) / 2;
			// mid 간격으로 하면 몇 마리 넣을 수 있는지 확인
			// 입력한 마리수 c보다 값이 크면 간격을 더 넓혀본다.
		if (Count(mid, magugan) >= c) {
			res = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d", res);
	delete[] magugan;
}