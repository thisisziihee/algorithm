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

		// 지금 출력되어야 할 문서는 우선순위 val 값을 가진 문서여야 한다.
		// 저장되어있는 문서들을 처음부터 탐색하면서, val 값과 다르면 맨 앞에 있는 문서를 맨 뒤로 보낸다.
		// 만약 val값과 일치한다면, 몇 번째 문서인지 m값과 비교해야하므로 pop은 나중에 진행하고 일단 while문을 나온다.
		while (true) {
			if (val == print_list.front().first) break;
			else {
				print_list.push(print_list.front());
				print_list.pop();
			}
		}

		// 해당 문서를 찾으면, 그 문서가 찾으려는 m번째 문서인지 확인한다.
		// 만약 다르면, pop
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