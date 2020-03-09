/*
�ڿ��� N�� �־����� 7*7 ������ �̷θ� Ż���ϴ� �ִܰ���� ��μ��� ����ϴ� ���α׷����ۼ��ϼ���. 
��μ��� ��������� ���������� ���µ� �̵��� Ƚ���� �ǹ��Ѵ�.  ������� ������ (1, 1) ��ǥ�̰�, Ż�� �������� (7, 7)��ǥ�̴�. 
�������� 1�� ���̰�, 0�� �����̴�. �������� �������� �����¿�θ� �����δ�. 
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
	// ��������� ������ �Ÿ�, 0�� �ƴϸ� �湮�� ������ ǥ��
	vector< vector<int> > board(7, vector<int>(7, 0));
	vector< vector<int> > dis(7, vector<int>(7, 0));
	queue< pair<int, int> > Q;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> board[i][j];
		}
	}
	Q.push(make_pair(0, 0));
	board[0][0] = 1;	// �湮�� ���� 1�� ǥ��

	while (!Q.empty()) {
		pair<int, int> tmp = Q.front();
		Q.pop();
		// ���� ��ġ tmp���� �����¿� ��ǥ �߿� ���� 0�� �ƴ� ��ǥ�� ������ Q.push
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