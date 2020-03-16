/*
N개의 도시가 주어지고, 각 도시들을 연결하는 도로와 해당 도로를 통행하는 비용이 주어질 때 
모든 도시에서 모든 도시로 이동하는데 쓰이는 비용의 최소값을 구하는 프로그램을 작성하세요.
▣ 입력설명
첫 번째 줄에는 도시의 수N(N<=100)과 도로수 M(M<=200)가 주어지고, M줄에 걸쳐 도로정보와 비용(20 이하의 자연수)이 주어진다. 
만약 1번 도시와 2번도시가 연결되고 그 비용이 13이면 “1 2 13”으로 주어진다.
▣ 출력설명
모든 도시에서 모든 도시로 이동하는데 드는 최소 비용을 아래와 같이 출력한다.
자기자신으로 가는 비용은 0입니다. i번 정점에서 j번 정점으로 갈 수 없을 때는 비용을 “M"으로 출력합니다.

5 8
1 2 6
1 3 3
3 2 2
2 4 1
2 5 13
3 4 5
4 2 3
4 5 7

*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, a, b, c;
	cin >> n >> m;

	// i에서 j로 가는 데에 최소 비용
	vector< vector<int> > dis(n + 1, vector<int>(n + 1, 5000));

	int i, j, k;
	
	// 인접행렬 초기화
	for( i = 1; i <= n; i++) dis[i][i] = 0;
	for (i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		dis[a][b] = c;
	}

	// 플로이드-와샬
	// i에서 j를 가는 데에 중간에 k 노드를 거치면서 가는 루트 확인
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (dis[i][j] == 5000) {
				cout << "M ";
			}
			else {
				cout << dis[i][j] << " ";
			}
		}
		cout << endl;
	}
}