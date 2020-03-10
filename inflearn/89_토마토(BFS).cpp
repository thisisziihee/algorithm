/*
현수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수있다. 
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 
대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다.
현수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
*/

#include <stdio.h>
#include <queue>

using namespace std;
int n, m, maxx = -2147000000;
int tomato[1010][1010];
int day[1010][1010];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

struct Loc {
	int x, y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};

queue<Loc> Q;

int main() {
	scanf("%d %d", &m, &n);
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1){
				Q.push(Loc(i, j));
			}
		}
	}

	// 익은 토마토를 Q.push하고 하나씩 꺼내서 상하좌우 토마토 익히기를 반복
	while (!Q.empty()) {
		Loc temp = Q.front();
		Q.pop();
		for (i = 0; i < 4; i++) {
			int xx = temp.x + dx[i];
			int yy = temp.y + dy[i];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
				if (tomato[xx][yy] == 0) {
					Q.push(Loc(xx, yy));
					tomato[xx][yy] = 1;
					day[xx][yy] = day[temp.x][temp.y] + 1;
				}
			}
		}
	}

	int ans = 1;
	// 안익은 토마토가 있는지 확인
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (tomato[i][j] == 0) {
				ans = 0;
				break;
			}
		}
	}

	// 토마토가 모두 익었으면 day 배열에 최댓값을 찾아서 출력
	// day의 최댓값은 토마토가 모두 익기까지 걸린 시간
	if (ans == 1) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				maxx = (maxx > day[i][j] ? maxx : day[i][j]);
			}
		}
		printf("%d", maxx);
	}

	// 안익은 토마토가 있으면 -1 출력
	else printf("-1");
	return 0;
}