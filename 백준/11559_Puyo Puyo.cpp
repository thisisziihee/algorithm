#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

/*
1. �ϳ��� �ѿ並 �������� �����¿� 4�� �̻��� ���� �� ������ �Ѳ����� ������
2. �������� ���� ���� �ִ� �ٸ� �ѿ���� ������
3. 1-2 ������ �� �� �ݺ��� ������ 1���⾿ �þ
4. ���� �� �ִ� �ѿ䰡 �����׷��׶�� ���ÿ� ��������
5. ���� �׷��� �������� �� ���� ���� �߰�

. �����  R ����. G �ʷ�. B �Ķ� . P ����. Y ���

�Է����� ���� �ѿ信�� �� ���Ⱑ �Ǵ��� ���
*/

char arr[12][6];
bool visited[12][6] = { false };
vector< pair<int, int> > group[20];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// 1. ���� ������ �������Ѵ�. 
// 2. 4�� �̻��̾����
bool check_puyo(int i, int j, int idx) {
	queue< pair<int, int> > Q;

	Q.push(make_pair(i, j));
	group[idx].push_back(make_pair(i, j));
	visited[i][j] = true;

	int x, y, nx, ny;
	int puyo_cnt = 1;

	while (!Q.empty()) {
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();
		for (int k = 0; k < 4; k++) {
			ny = y + dy[k];
			nx = x + dx[k];
			
			if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12) continue;
			if (visited[ny][nx]) continue;
			if (arr[ny][nx] != arr[i][j]) continue;

			visited[ny][nx] = true;
			Q.push(make_pair(ny, nx));
			group[idx].push_back(make_pair(ny, nx));
			puyo_cnt += 1;
		}
	}

	if (puyo_cnt < 4) {
		for (int k = 0; k < group[idx].size(); k++) {
			y = group[idx][k].first;
			x = group[idx][k].second;
			visited[y][x] = false;
		}
		group[idx].clear();
		return false;
	}
	return true;
}


void drag_puyo_down(int x) {
	for (int i = 11; i > 0; i--) {
		if (arr[i][x] == '.' && i > 0) {
			int y = i - 1;
			while (y >= 0) {
				if (arr[y][x] != '.') {
					arr[i][x] = arr[y][x];
					arr[y][x] = '.';
					break;
				}
				y -= 1;
			}
		}
	}
}

int main() {
	int ans = 0;

	// 1. ������ �ѿ� �־���
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}

	// 2. �� �̻� ���� �ѿ䰡 ���� �� ���� ���� 
	while(true) {

		// (1) ���� ��Ȳ���� ���� �ѿ� Ȯ�� (���� �׷�)
		for (int i = 0; i < 20; i++) {
			group[i].clear();
		}
		memset(visited, false, sizeof(visited));

		int idx = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (visited[i][j] || arr[i][j] == '.') continue;
				if (check_puyo(i, j, idx)) idx += 1;
			}
		}

		// (2) �� �̻� ���� �ѿ� ������ while�� Ż��
		if (idx == 0) break;


		// (3) �ش�Ǵ� �ѿ� ���ֱ�
		for (int i = 0; i < 20; i++) {
			if (group[i].size() == 0) continue;
			else {
				for (int k = 0; k < group[i].size(); k++) {
					int y = group[i][k].first;
					int x = group[i][k].second;
					arr[y][x] = '.';
				}
			}
		}

		// (4) ���� �ִ� �ѿ�� ������
		for (int x = 0; x < 6; x++) {
			drag_puyo_down(x);
		}

		// (5) 1���� �߰�
		ans += 1;
	}

	// 3. ������ �ѿ信 ���� ���Ⱚ ���
	cout << ans << endl;
	
}