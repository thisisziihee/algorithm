#include <iostream>
#include <queue>

using namespace std;

void solution(int n, int m) {
	queue< pair<int, int> > print_list;
	priority_queue<int> Q;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		print_list.push(make_pair(num, i));
		Q.push(num);
	}

	int cnt = 0;
	while (true) {
		cnt += 1;
		int val = Q.top();
		Q.pop();

		// ���� ��µǾ�� �� ������ �켱���� val ���� ���� �������� �Ѵ�.
		// ����Ǿ��ִ� �������� ó������ Ž���ϸ鼭, val ���� �ٸ��� �� �տ� �ִ� ������ �� �ڷ� ������.
		// ���� val���� ��ġ�Ѵٸ�, �� ��° �������� m���� ���ؾ��ϹǷ� pop�� ���߿� �����ϰ� �ϴ� while���� ���´�.
		while (true) {
			if (val == print_list.front().first) break;
			else {
				print_list.push(print_list.front());
				print_list.pop();
			}
		}

		// �ش� ������ ã����, �� ������ ã������ m��° �������� Ȯ���Ѵ�.
		// ���� �ٸ���, pop
		if (print_list.front().second == m) {
			cout << cnt << endl;
			break;
		}
		else print_list.pop();
	}
}

int main() {
	int tc, n, m;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> n >> m;
		solution(n, m);
	}	
	return 0;
}