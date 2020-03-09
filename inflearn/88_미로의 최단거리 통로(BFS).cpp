/*
자연수 N이 주어지면 7*7 격자판 미로를 탈출하는 최단경로의 경로수를 출력하는 프로그램을작성하세요. 
경로수는 출발점에서 도착점까지 가는데 이동한 횟수를 의미한다.  출발점은 격자의 (1, 1) 좌표이고, 탈출 도착점은 (7, 7)좌표이다. 
격자판의 1은 벽이고, 0은 도로이다. 격자판의 움직임은 상하좌우로만 움직인다. 
*/

#include <iostream>
#include <queue>
#include <vector>

#define x first
#define y second
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	// 출발점으로 부터의 거리, 0이 아니면 방문한 것으로 표시
	vector< vector<int> > board(7, vector<int>(7, 0));
	vector< vector<int> > dis(7, vector<int>(7, 0));
	queue< pair<int, int> > Q;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> board[i][j];
		}
	}
	Q.push(make_pair(0, 0));
	board[0][0] = 1;	// 방문한 곳은 1로 표시

	while (!Q.empty()) {
		pair<int, int> tmp = Q.front();
		Q.pop();
		// 현재 위치 tmp에서 상하좌우 좌표 중에 값이 0이 아닌 좌표가 있으면 Q.push
		for (int i = 0; i < 4; i++) {
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			if (xx >= 0 && xx < 7 && yy >= 0 && yy < 7 && board[xx][yy] == 0) {
				Q.push(make_pair(xx, yy));
				board[xx][yy] = 1;
				dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
			}
		}
	}
	if (dis[6][6] == 0) cout << "-1";
	else cout << dis[6][6];
	return 0;
}