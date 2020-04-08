/*
 'Dummy' 라는 도스게임이 있다. 이 게임에는 뱀이 나와서 기어다니는데, 사과를 먹으면 뱀 길이가 늘어난다. 
 뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.

게임은 NxN 정사각 보드위에서 진행되고, 몇몇 칸에는 사과가 놓여져 있다. 보드의 상하좌우 끝에 벽이 있다. 
게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.

뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.

먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.

입력
첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)
다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다. 사과의 위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.

다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)
다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데,  정수 X와 문자 C로 이루어져 있으며. 
게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. X는 10,000 이하의 양의 정수이며, 
방향 전환 정보는 X가 증가하는 순으로 주어진다.

출력
첫째 줄에 게임이 몇 초에 끝나는지 출력한다.
*/

#include<bits/stdc++.h>
using namespace std;

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, -1, 1, 0, 0 };

struct Snake {
	int head_x, head_y;
	// 상1 하2 좌3 우4
	int dir;
};

int main() {
	int n, k, l;
	
	cin >> n;
	vector< vector<int> > arr(n, vector<int>(n, 0));
	
	cin >> k;
	int y, x;
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		arr[y-1][x-1] = 1;
	}

	cin >> l;
	queue< pair<int, char> > Q;
	vector< pair<int, int> > snake_body;
	int sec;
	char dir;
	for (int i = 0; i < l; i++) {
		cin >> sec >> dir;
		Q.push(make_pair(sec, dir));
	}

	Snake bam;
	bam.head_x = bam.head_y = 0;
	bam.dir = 4;
	snake_body.push_back(make_pair(0, 0));

	int time = 0;
	while (true) {
		time += 1;
		{
			bam.head_x = bam.head_x + dx[bam.dir];
			bam.head_y = bam.head_y + dy[bam.dir];

			// 뱀이 움직인 위치가 범위 안에 있는 경우
			if (bam.head_x >= 0 && bam.head_x < n && bam.head_y >= 0 && bam.head_y < n) {

				// 뱀이 새로 이동했는데 자기 몸통이랑 부딪힌 경우
				int exit_flag = 0;
				for (int idx = 0; idx < snake_body.size(); idx++) {
					if (snake_body[idx].first == bam.head_y && snake_body[idx].second == bam.head_x) {
						exit_flag = 1;
						break;
					}
				}
				if (exit_flag == 1) break;

				// 제대로 위치한 경우
				{
					snake_body.insert(snake_body.begin(), make_pair(bam.head_y, bam.head_x));
					if (arr[bam.head_y][bam.head_x] == 1) {
						arr[bam.head_y][bam.head_x] = 0;
					}
					else {
						snake_body.pop_back();
					}
				}
			}

			// 벽에 부딪히면 게임 끝
			else {
				break;
			}
		}
		if (Q.empty() != true && Q.front().first == time) {
			if (Q.front().second == 'L') { // 왼쪽으로 방향 전환
				if (bam.dir == 1) bam.dir = 3;
				else if (bam.dir == 2) bam.dir = 4;
				else if (bam.dir == 3) bam.dir = 2;
				else if (bam.dir == 4) bam.dir = 1;
			}
			else { // 오른쪽으로 방향 전환
				if (bam.dir == 1) bam.dir = 4;
				else if (bam.dir == 2) bam.dir = 3;
				else if (bam.dir == 3) bam.dir = 1;
				else if (bam.dir == 4) bam.dir = 2;
			}
			Q.pop();
		}
	}
	cout << time << endl;
}