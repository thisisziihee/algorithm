/*
N×N 크기의 정글에 토끼 M마리와 배고픈 어린 사자 심바가 있다. 정글은 1×1 크기의 정사각형 칸으로 나누어져 있다.
한 칸에는 토끼가 최대 1마리 존재한다. 심바는 주어진 정글에서 토끼를 잡아먹고 덩치를 키워 삼촌 스카에게 복수를 하러 갈 예정이다.
어린 사자 심바와 토끼는 모두 크기를 가지고 있고, 이 크기는 자연수이다.
가장 처음에 어린사자 심바의 크기는 2이고, 심바는 1초에 상하좌우로 인접한 한 칸씩 이동한다.
어린 사자 심바는 자신의 크기보다 큰 토끼가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
심바는 자신의 크기보다 작은 토끼만 먹을 수 있다. 따라서, 크기가 같은 토끼는 먹을 수 없지만, 그 토끼가 있는 칸은 지나갈 수 있다.
어린 사자 심바가 어디로 이동할지 결정하는 방법은 아래와 같다.
• 더 이상 먹을 수 있는 토끼가 정글에 없다면 비로소 어린 사자 심바는 삼촌 스카에게 복수하러 갈 수 있다.
• 먹을 수 있는 토끼가 1마리라면, 그 토끼를 먹으러 간다.
• 먹을 수 있는 토끼가 1마리보다 많다면, 거리가 가장 가까운 토끼를 먹으러 간다.
 ∘ 거리는 심바가 있는 칸에서 토끼가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최소값이다.
 ∘ 거리가 가까운 토끼가 많다면, 가장 위에 있는 토끼, 그러한 토끼가 여러 마리라면, 가장 왼쪽에 있는 토끼를 먹는다.
심바의 이동은 1초 걸리고, 토끼를 먹는데 걸리는 시간은 없다고 가정한다.
즉, 심바가 먹을 수 있는 토끼가 있는 칸으로 이동했다면, 이동과 동시에 토끼를 먹는다.
토끼를 먹으면, 그 칸은 빈 칸이 된다. 심바는 자신의 크기와 같은 수의 토끼를 먹을 때 마다 크기가 1 증가한다.
예를 들어, 크기가 2인 심바는 토끼를 2마리 먹으면 크기가 3이 된다.
정글의 상태가 주어졌을 때, 심바가 몇 초 동안 토끼를 잡아먹고 삼촌 스카에게 복수를 하러 갈 수 있는지 구하는 프로그램을 작성하시오.
*/

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int map[21][21];
int check[21][21];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct State {
	// 심바가 움직이는 좌표(x, y)와 거리(dis)
	int x, y, dis;
	State(int a, int b, int c) {
		x = a;
		y = b;
		dis = c;
	}

	// 거리가 같지 않으면, 최소 힙으로 가장 거리가 짧은 좌표가 top
	// 거리가 같으면, x좌표가 우선 순위, x 좌표도 같다면 y좌표 우선순위
	bool operator<(const State &bb) const {
		if (dis == bb.dis) {
			if (x == bb.x) return y > bb.y;
			else return x > bb.x;
		}
		else return dis > bb.dis;
	}
};

struct Lion {
	int x, y, size, ate;
	// sizeUp 함수 호출되면, 먹은 횟수 0으로 초기화. 사이즈 1 증가
	void sizeUp() {
		ate = 0;
		size += 1;
	}
};

int main() {
	int n, i, j, res = 0;

	priority_queue<State> Q;
	Lion simba;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				// 심바의 위치 확인. 심바는 움직이니까 map[i][j] = 0;
				simba.x = i;
				simba.y = j;
				map[i][j] = 0;
			}
		}
	}

	Q.push(State(simba.x, simba.y, 0));
	simba.size = 2;
	simba.ate = 0;
	while (!Q.empty()) {
		State tmp = Q.top();
		Q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;

		// map[x][y]에 위치한 토끼를 잡아먹을 수 있는지 확인
		if (map[x][y] != 0 && map[x][y] < simba.size) {
			// 토끼를 잡아먹으면서 토끼가 있던 위치로 이동
			simba.x = x;
			simba.y = y;
			simba.ate += 1;

			// 사이즈업 할 수 있는지 확인
			if (simba.ate >= simba.size) simba.sizeUp();

			// 잡아먹은 토끼의 위치는 0으로 빈칸 처리
			map[x][y] = 0;

			// 방문 배열 초기화. 다시 출발해야하니까
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					check[i][j] = 0;
				}
			}
			while (!Q.empty()) Q.pop();

			// 한번 잡아먹고 나서 최초 출발부터 지금까지 토끼를 잡아먹기 위해 움직인 거리 갱신
			res = tmp.dis;
		}

		// 심바의 위치에서 상하좌우 확인
		for (i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			// 상하좌우가 경계선을 벗어나거나 심바 사이즈보다 크거나 이미 방문한 좌표라면 continue;
			if (xx<1 || xx >n || yy <1 || yy>n || map[xx][yy] > simba.size || check[xx][yy] > 0) continue;

			// [xx][yy] 좌표가 조건에 맞는다면 이동. 한 칸 움직였으니까 z+1하고 Q.push
			// z는 현재까지 심바가 움직인 거리 
			Q.push(State(xx, yy, z + 1));
			check[xx][yy] = 1;
		}
	}
	printf("%d", res);
	return 0;
}