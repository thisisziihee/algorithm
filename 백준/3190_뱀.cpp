/*
 'Dummy' ��� ���������� �ִ�. �� ���ӿ��� ���� ���ͼ� ���ٴϴµ�, ����� ������ �� ���̰� �þ��. 
 ���� �̸����� ���ٴϴٰ� �� �Ǵ� �ڱ��ڽ��� ���� �ε����� ������ ������.

������ NxN ���簢 ���������� ����ǰ�, ��� ĭ���� ����� ������ �ִ�. ������ �����¿� ���� ���� �ִ�. 
������ �����Ҷ� ���� ���� �������� ��ġ�ϰ� ���� ���̴� 1 �̴�. ���� ó���� �������� ���Ѵ�.

���� �� �ʸ��� �̵��� �ϴµ� ������ ���� ��Ģ�� ������.

���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�. ��, �����̴� ������ �ʴ´�.
����� ��ġ�� ���� �̵���ΰ� �־��� �� �� ������ �� �ʿ� �������� ����϶�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. (2 �� N �� 100) ���� �ٿ� ����� ���� K�� �־�����. (0 �� K �� 100)
���� K���� �ٿ��� ����� ��ġ�� �־����µ�, ù ��° ������ ��, �� ��° ������ �� ��ġ�� �ǹ��Ѵ�. ����� ��ġ�� ��� �ٸ���, �� �� �� ���� (1�� 1��) ���� ����� ����.

���� �ٿ��� ���� ���� ��ȯ Ƚ�� L �� �־�����. (1 �� L �� 100)
���� L���� �ٿ��� ���� ���� ��ȯ ������ �־����µ�,  ���� X�� ���� C�� �̷���� ������. 
���� ���� �ð����κ��� X�ʰ� ���� �ڿ� ����(C�� 'L') �Ǵ� ������(C�� 'D')�� 90�� ������ ȸ����Ų�ٴ� ���̴�. X�� 10,000 ������ ���� �����̸�, 
���� ��ȯ ������ X�� �����ϴ� ������ �־�����.

���
ù° �ٿ� ������ �� �ʿ� �������� ����Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, -1, 1, 0, 0 };

struct Snake {
	int head_x, head_y;
	// ��1 ��2 ��3 ��4
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

			// ���� ������ ��ġ�� ���� �ȿ� �ִ� ���
			if (bam.head_x >= 0 && bam.head_x < n && bam.head_y >= 0 && bam.head_y < n) {

				// ���� ���� �̵��ߴµ� �ڱ� �����̶� �ε��� ���
				int exit_flag = 0;
				for (int idx = 0; idx < snake_body.size(); idx++) {
					if (snake_body[idx].first == bam.head_y && snake_body[idx].second == bam.head_x) {
						exit_flag = 1;
						break;
					}
				}
				if (exit_flag == 1) break;

				// ����� ��ġ�� ���
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

			// ���� �ε����� ���� ��
			else {
				break;
			}
		}
		if (Q.empty() != true && Q.front().first == time) {
			if (Q.front().second == 'L') { // �������� ���� ��ȯ
				if (bam.dir == 1) bam.dir = 3;
				else if (bam.dir == 2) bam.dir = 4;
				else if (bam.dir == 3) bam.dir = 2;
				else if (bam.dir == 4) bam.dir = 1;
			}
			else { // ���������� ���� ��ȯ
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