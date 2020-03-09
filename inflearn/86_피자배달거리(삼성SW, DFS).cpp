/*
ũ�Ⱑ N��N�� ���ð� �ִ�. ���ô� 1��1ũ���� ĭ���� �������� �ִ�. ������ �� ĭ�� �� ĭ, ������, �� �� �ϳ��̴�. 
������ ĭ�� (r, c)�� ���� ���·� ��Ÿ����, r�� c�� �Ǵ� ���������� r��° ĭ, ���ʿ������� c��° ĭ�� �ǹ��Ѵ�.
r�� c�� 1���� �����Ѵ�. �� ���ÿ� ��� ������� ���ڸ� ��޽��� �Դ� ���� �ʹ� �����Ѵ�.
����, ������� "���� ��� �Ÿ�"��� ���� �ַ� ����Ѵ�. �� ������ ������ ������ ������ ���� ��� �Ÿ��� �ִµ�, �� ���� ���� ��� �Ÿ��� �Ʒ��� ���� ���ȴ�.
������ �� ĭ (r1, c1)�� (r2, c2) ������ �Ÿ��� |r1-r2| + |c1-c2|�� ���Ѵ�. �� ������ �� ���� ������ �����. 
�ʹ� ���ڰ� �αⰡ �ִ� ���� �ʵ� ���� �������� ���� �ʹ� ���� ���������� �������� �Ļ��� �ϴ� �Ļ��ϴ� �������� �����Ͽ� ������ ������ �������� M���� �����ϱ�� �ߴ�.
������ ���ÿ� �ִ� ������ �߿��� �ִ� M���� ����, ������ �������� ��� ������Ѿ� �Ѵ�. 
��� ����, ������ ���� ��� �Ÿ��� ���� �۰� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ������ ���� ��� �Ÿ��� �� ������ ���� ��� �Ÿ��� ���� ���� ���Ѵ�.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int, int> > pizza;
vector< pair<int, int> > house;
int pizza_list[14];
int minn = 2147000000;
int pizza_limit, dis, sum = 0;

// level : vector pizza index
// cnt : pizza_list index
void dfs(int level, int cnt) {
	if (level > pizza.size()) return;
	// m���� �������� ��� ������ ���
	if (cnt == pizza_limit) {
		sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int x1 = house[i].first;
			int y1 = house[i].second;
			// dis : house[i] ���� ���ؼ� ��� ���� ��� �Ÿ� �� ���� �ּҰ� ã��
			// house ������ �� <-> pizza_list�� ������ ������ ������ ���ڹ�ްŸ�
			dis = 2147000000;
			for (int j = 0; j < pizza_limit; j++) {
				int x2 = pizza[pizza_list[j]].first;
				int y2 = pizza[pizza_list[j]].second;
				dis = min(dis, abs(x1 - x2) + abs(y1 - y2));
			}
			// �� ������ ���� ��� �Ÿ� �ּڰ� ���� : �� ������ ���ڹ�ްŸ� ��
			sum += dis;
		}
		// ������ ���ո��� minn ���� ������ ���� ��ްŸ� �ּڰ�
		if (sum < minn) minn = sum;
	}
	else {
		pizza_list[cnt] = level;
		dfs(level + 1, cnt + 1);
		dfs(level + 1, cnt);
	}
}

int main() {
	int n, i, j, a;
	scanf("%d %d", &n, &pizza_limit);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a);
			if (a == 1) house.push_back(make_pair(i, j));
			else if (a == 2) pizza.push_back(make_pair(i, j));
		}
	}

	// DFS�� ���ؼ� m���� ������ ������ ���ϰ�
	// �� ���տ� ���� ���� ��� �Ÿ��� ���Ѵ�.
	dfs(0, 0);
	printf("%d", minn);
	return 0;
}