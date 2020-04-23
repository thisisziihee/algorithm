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

		// now 형태의 i번째 막대에서 j번째 막대로 옮기기
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// 두 개가 같은 막대이거나 i번째 막대에 옮길 원판이 없는 경우
				if (i == j) continue;
				if (now[i].length() == 0) continue;
				
				// i 막대의 가장 위에 있는 원판을 j 막대로 옮겨서 배열 next 만든다.
				array<string, 3> next(now);
				next[j].push_back(next[i].back());
				next[i].pop_back();

				// next에 대해서 이전에 만들었던 형태가 아니라면 dist에 새로운 형태 next를 저장한다. 
				// dist[now] 보다 1번 더 움직인 횟수 저장
				// 그리고 새로운 하노이탑 배열 next를 Q.push
				if (dist.count(next) == 0) {
					dist[next] = dist[now] + 1;
					Q.push(next);
				}
			}
		}
	}

	// 하노이탑 완성 배열 ans
	array<string, 3> ans;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			ans[i] += (char)'A' + i;
		}
	}

	// ans 형태를 갖는 배열이 몇번의 이동 횟수를 갖는지 출력
	cout << dist[ans] << endl;
	return 0;
}