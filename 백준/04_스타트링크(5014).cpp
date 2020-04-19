#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int F, G, S, up, down;

	cin >> F >> S >> G >> up >> down;

	// �ش� ������ ���� ���� ��ư�� �� �� ������ �ϴ��� ����
	// -1���� �ʱ�ȭ�Ͽ� �� ���� �湮���� ���� ���� -1���� ���´�.
	vector<int> dist(F + 1, -1);
	queue<int> stairs;

	stairs.push(S);
	dist[S] = 0;
	int now;

	while (!stairs.empty()) {
		now = stairs.front();
		stairs.pop();

		// F�� ���� 1�� �̻��� ������ ������ �ѹ��� �湮���� ���� ���� ���
		if (now + up <= F && dist[now + up] == -1) {
			stairs.push(now + up);
			dist[now + up] = dist[now] + 1;
		}
		if (now - down >= 1 && dist[now - down] == -1) {
			stairs.push(now - down);
			dist[now - down] = dist[now] + 1;
		}
	}

	if (dist[G] != -1) cout << dist[G] << endl;
	else cout << "use the stairs" << endl;
}