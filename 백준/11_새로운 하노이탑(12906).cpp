#include <iostream>
#include <string>
#include <queue>
#include <array>
#include <map>

using namespace std;

int main() {
	array<string, 3> arr;

	int num;
	for (int i = 0; i < 3; i++) {
		cin >> num;
		if (num > 0) cin >> arr[i];
		else arr[i] = "";
	}

	int cnt[3] = { 0, 0, 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < arr[i].length(); j++) {
			cnt[arr[i][j] - 'A'] += 1;
		}
	}


	map<array<string, 3>, int> dist;
	dist[arr] = 0;

	queue< array<string, 3> > Q;
	Q.push(arr);

	while (!Q.empty()) {
		auto now = Q.front();
		Q.pop();

		// now ������ i��° ���뿡�� j��° ����� �ű��
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// �� ���� ���� �����̰ų� i��° ���뿡 �ű� ������ ���� ���
				if (i == j) continue;
				if (now[i].length() == 0) continue;
				
				// i ������ ���� ���� �ִ� ������ j ����� �Űܼ� �迭 next �����.
				array<string, 3> next(now);
				next[j].push_back(next[i].back());
				next[i].pop_back();

				// next�� ���ؼ� ������ ������� ���°� �ƴ϶�� dist�� ���ο� ���� next�� �����Ѵ�. 
				// dist[now] ���� 1�� �� ������ Ƚ�� ����
				// �׸��� ���ο� �ϳ���ž �迭 next�� Q.push
				if (dist.count(next) == 0) {
					dist[next] = dist[now] + 1;
					Q.push(next);
				}
			}
		}
	}

	// �ϳ���ž �ϼ� �迭 ans
	array<string, 3> ans;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			ans[i] += (char)'A' + i;
		}
	}

	// ans ���¸� ���� �迭�� ����� �̵� Ƚ���� ������ ���
	cout << dist[ans] << endl;
	return 0;
}