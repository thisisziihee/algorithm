#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int F, G, S, up, down;

	cin >> F >> S >> G >> up >> down;

	// 해당 층까지 가기 위해 버튼을 몇 번 눌러야 하는지 저장
	// -1으로 초기화하여 한 번도 방문하지 않은 층은 -1값을 갖는다.
	vector<int> dist(F + 1, -1);
	queue<int> stairs;

	stairs.push(S);
	dist[S] = 0;
	int now;

	while (!stairs.empty()) {
		now = stairs.front();
		stairs.pop();

		// F층 이하 1층 이상의 범위를 가지며 한번도 방문하지 않은 층인 경우
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