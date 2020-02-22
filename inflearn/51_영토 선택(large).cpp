/*
세종대왕은 현수에게 현수가 다스릴 수 있는 영지를 하사하기로 했다. 전체 땅은 사각형으로 표시된다.
그 사각형의 땅 중에서 다스릴 수 있는 땅의 크기(세로의 길이와 가로의 길이)를 정해주면 전체 땅 중에서 그 크기의 땅의 위치를 현수가 정하면 되는 것이다.
전체 땅은 사각형의 모양의 격자로 되어 있으며, 그 사각형 땅 안에는 많은 오렌지 나무가 심겨져 있다.
현수는 오렌지를 무척 좋아하여 오렌지 나무가 가장 많이 포함되는 지역을 선택하고 싶어 한다.
현수가 얻을 수 있는 영지의 오렌지 나무 최대 개수를 출력하는 프로그램을 작성하세요.

▣ 입력설명 : 첫 줄에 H(세로길이)와 W(가로길이)가 입력된다. (5<=H, W<=700) 그 다음 H줄에 걸쳐 각 사각형 지역에 오렌지의 나무 개수(1~9개) 정보가 주어진다.
			  그 다음 영지의 크기인 세로길이(1~H)와 가로길이(1~W)가 차례로 입력된다.
▣ 출력설명 : 첫 줄에 현수가 얻을 수 있는 오렌지 나무의 최대 개수를 출력한다.
*/

#include<stdio.h>

	// 전역변수로 처리해야 시간제한 안에 처리될 수 있다.
int territory[701][701];
int dy[701][701];
int main() {
	int h, w, i, j, hh, ww;
	int temp = 0, max = -2147000000;

	scanf("%d %d", &h, &w);
	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			scanf("%d", &territory[i][j]);
			dy[i][j] = (dy[i - 1][j] + dy[i][j - 1] - dy[i - 1][j - 1] + territory[i][j]);
		}
	}

	scanf("%d %d", &hh, &ww);
	for (i = hh; i <= h; i++) {
		for (j = ww; j <= w; j++) {
			temp = dy[i][j] - dy[i - hh][j] - dy[i][j - ww] + dy[i - hh][j - ww];
			max = (temp > max ? temp : max);
		}
	}

	printf("%d", max);
	return 0;
}