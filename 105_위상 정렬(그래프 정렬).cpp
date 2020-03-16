/*
위상정렬은 어떤 일을 하는 순서를 찾는 알고리즘입니다.
각각의 일의 선후관계가 복잡하게 얽혀있을 때 각각 일의 선후관계를 유지하면서 전체 일의 순서를 짜는 알고리즘입니다.
만약 아래와 같은 일의 순서를 각각 지키면서 전체 일의 순서를 정한다면
1 4 //1번일을 하고 난 후 4번일을 해야한다.
5 4
4 3
2 5
2 3
6 2
전체 일의 순서는 1, 6, 2, 5, 4, 3과 같이 정할 수 있다. 전체 일의 순서는 여러 가지가 있습니다 그 중에 하나입니다.

▣ 입력설명
첫 번째 줄에 전체 일의 개수 N과 일의 순서 정보의 개수 M이 주어집니다.
두 번째 줄부터 M개의 정보가 주어집니다.
▣ 출력설명 : 전체 일의 순서를 출력합니다.

6 6
1 4
5 4
4 3
2 5
2 3
6 2
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector< vector<int> > dis(n + 1, vector<int>(n + 1));
	 
	// degree : 진입 차수 : 해당 정점으로 들어오는 노드의 개수
	// 진입 차수가 0이면, 먼저 해야 할 작업이 아무것도 없으니까 가장 먼저 처리
	vector<int> degree(n + 1, 0);
	
	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dis[a][b] = 1;
		degree[b]++;
	}

	// 전입차수 0인 것을 큐에 넣어서 순서에 제약받지 않는 작업 먼저 처리
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) Q.push(i);
	}

	for (int i = 1; i <= n; i++) cout << degree[i] << " ";
	cout << endl;

	while (!Q.empty()) {
		int index = Q.front();
		cout << index << " ";
		Q.pop();

		for (int i = 1; i <= n; i++) {
			if (dis[index][i] == 1) {
				dis[index][i] = 0;
				degree[i]--;
				if (degree[i] == 0) Q.push(i);
			}
		}
	}

}