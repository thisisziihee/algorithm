/*
크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 도시의 각 칸은 빈 칸, 피자집, 집 중 하나이다. 
도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다.
r과 c는 1부터 시작한다. 이 도시에 사는 사람들은 피자를 배달시켜 먹는 것을 너무 좋아한다.
따라서, 사람들은 "피자 배달 거리"라는 말을 주로 사용한다. 이 도시의 각각의 집들은 각자의 피자 배달 거리가 있는데, 각 집의 피자 배달 거리는 아래와 같이 계산된다.
임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다. 이 도시의 한 가지 문제가 생겼다. 
너무 피자가 인기가 있다 보니 너도 나도 피자집을 차려 너무 많은 피자집들의 경쟁으로 파산을 하는 파산하는 피자집이 속출하여 도시의 시장은 피자집을 M개로 제한하기로 했다.
시장은 도시에 있는 피자집 중에서 최대 M개를 고르고, 나머지 피자집은 모두 폐업시켜야 한다. 
어떻게 고르면, 도시의 피자 배달 거리가 가장 작게 될지 구하는 프로그램을 작성하시오. 도시의 피자 배달 거리는 각 집들의 피자 배달 거리를 합한 것을 말한다.
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
	// m개의 피자집을 모두 조합한 경우
	if (cnt == pizza_limit) {
		sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int x1 = house[i].first;
			int y1 = house[i].second;
			// dis : house[i] 집에 대해서 모든 피자 배달 거리 중 가장 최소값 찾음
			// house 각각의 집 <-> pizza_list에 선정된 피자집 사이의 피자배달거리
			dis = 2147000000;
			for (int j = 0; j < pizza_limit; j++) {
				int x2 = pizza[pizza_list[j]].first;
				int y2 = pizza[pizza_list[j]].second;
				dis = min(dis, abs(x1 - x2) + abs(y1 - y2));
			}
			// 각 집마다 피자 배달 거리 최솟값 누적 : 이 지역의 피자배달거리 합
			sum += dis;
		}
		// 피자집 조합마다 minn 갱신 도시의 피자 배달거리 최솟값
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

	// DFS을 통해서 m개의 피자집 조합을 구하고
	// 각 조합에 따른 피자 배달 거리를 구한다.
	dfs(0, 0);
	printf("%d", minn);
	return 0;
}