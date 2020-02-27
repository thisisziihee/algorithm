/*
자연수 N이 주어지면 7*7 격자판 미로를 탈출하는 경로의 가지수를 출력하는 프로그램을 작성하세요. 
출발점은 격자의 (1, 1) 좌표이고, 탈출 도착점은 (7, 7)좌표이다. 격자판의 1은 벽이고, 0은 통로이다. 
격자판의 움직임은 상하좌우로만 움직인다. 미로가 다음과 같다면
출발 0 0 0 0 0 0
0 1 1 1 1 1 0
0 0 0 1 0 0 0
1 1 0 1 0 1 1
1 1 0 0 0 0 1
1 1 0 1 1 0 0
1 0 0 0 0 0 도착
위의 지도에서 출발점에서 도착점까지 갈 수 있는 방법의 수는 8가지이다
*/
#include<stdio.h>
int map[8][8];
int check[8][8];
int cnt = 0;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	if (x == 7 && y == 7) {
		cnt++;
	}
	else {
		// 현위치(x,y)에서 어디로 움직일지 상하좌우 체크
		// 다음 위치는 방문하지 않아야 하며, 벽이 아니여야함
		int nextX, nextY;
		for (int i = 0; i < 4; i++) {
			nextX = x + dx[i];
			nextY = y + dy[i];
			if (nextX >= 1 && nextX <= 7 && nextY <= 7 && nextY >= 1 ){
				if (map[nextX][nextY] == 0 && check[nextX][nextY] == 0) {
					check[nextX][nextY] = 1;
					dfs(nextX, nextY);
					check[nextX][nextY] = 0;
				}
			}
		}
	}
}

int main() {
	int i, j;
	for (i = 1; i <= 7; i++) {
		for (j = 1; j <= 7; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	check[1][1] = 1;
	dfs(1, 1);
	printf("%d", cnt);
}