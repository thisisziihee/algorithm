/*
밑면이 정사각형인 직육면체 벽돌들을 사용하여 탑을 쌓고자 한다. 탑은 벽돌을 한 개씩 아래에서 위로 쌓으면서 만들어간다.
아래의 조건을 만족하면서 가장 높은 탑을 쌓을  수 있는 프로그램을 작성하시오.
(조건1) 벽돌은 회전시킬 수 없다. 즉, 옆면을 몉면으로 사용할 수 없다.
(조건2) 밑면의 넓이가 같은 벽돌은 없으며, 또한 무게가 같은 벽돌도 없다.
(조건3) 벽돌들의 높이는 같을 수도 있다.
(조건4) 탑을 쌓을 때 밑면이 좁은 벽돌 위에 밑면이 넓은 벽돌은 놓을 수 없다.
(조건5) 무게가 무거운 벽돌을 무게가 가벼운 벽돌 위에 놓을 수 없다.

입력 :
입력 파일의 첫쨰 줄에는 입력될 벽돌의 수가 주어진다. 입력으로 주어지는 벽돌의 수는 최대 100개이다.
둘째 줄부터는 각 줄에 한 개의 벽돌에 관한 정보인 벽돌 밑면의 넓이, 벽돌의 높이 그리고 무게가
차례대로 야의 정수로 주어진다. 각 벽돌은 입력되는 순서대로 1부터 연속적인 번호를 가진다.
*/

/*
5
25 3 4
4 4 6
9 2 3
16 2 5
1 5 2
*/

#include <bits/stdc++.h>

using namespace std;

struct Brick {
	int s, h, w;
	Brick(int a, int b, int c) {
		s = a;
		h = b;
		w = c;
	}
	// s 에 의한 내림차순
	// 앞의 자료가 뒤의 자료(a)보다 크면 ture
	// 연산자를 호출한 게 앞의 자료 매개변수로 넘어온게 뒤의 자료
	bool operator < (const Brick &a) const{
		return s > a.s;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, s, h, w;
	int res = 0, max_h = 0;
	cin >> n;

	vector<Brick> bricks;
	vector<int> dy(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> s >> h >> w;
		bricks.push_back(Brick(s, h, w));
	}
	sort(bricks.begin(), bricks.end());


	dy[0] = bricks[0].h;
	res = dy[0];

	// dy의 i 번째 값은 i번째 벽돌이 가장 위에 있을 때 만들 수 있는 탑의 최대 높이
	for (int i = 1; i < n; i++) {
		max_h = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (bricks[i].w < bricks[j].w && dy[j] > max_h) {
				max_h = dy[j];
			}
		}
		dy[i] = max_h + bricks[i].h;
		res = res > dy[i] ? res : dy[i];
	}
	cout << res << endl;
	return 0;
}