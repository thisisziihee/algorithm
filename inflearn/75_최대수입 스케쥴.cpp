/*
현수는 유명한 강연자이다. N개이 기업에서 강연 요청을 해왔다. 각 기업은 D일 안에 와서 강연을 해 주면 M만큼의 강연료를 주기로 했다.
각 기업이 요청한 D와 M를 바탕으로 가장 많을 돈을 벌 수 있도록 강연 스케쥴을 짜야 한다.
단 강연의 특성상 현수는 하루에 하나의 기업에서만 강연을 할 수 있다.
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Data {
	int money;
	int when;
	Data(int a, int b) {
		money = a;
		when = b;
	}
	bool operator < (Data &b) {
		return when > b.when;
	}
};


int main() {
	int n, i, j, m, d, res = 0, max = -2147000000;

	vector <Data> T;			// 강연 마감기한과 강연료에 대한 구조체 Data 형식으로 된 벡터 T
	priority_queue<int> pQ;		// 해당 날짜에 할 수 있는 강연의 강연료를 담은 우선순위 큐 pQ
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &m, &d);
		T.push_back(Data(m, d));
		if (d > max) max = d;
	}

	sort(T.begin(), T.end());	// 강연 날짜를 기준으로 내림차순 정렬 ( Data 구조체에서 정의한 < 연산자에 의해)

	j = 0;
	for (i = max; i >= 1; i--) { // 마지막 강연 날짜부터 내림차순으로 스케쥴링

		for (; j < n; j++) {	 // i일에 할 수 있는 강연 찾기

			if (T[j].when < i) break;	// 마감기한 i일보다 더 작은 마감기한을 갖는 경우에는 break
			pQ.push(T[j].money);		// i 마감날짜보다 크거나 같은 강연의 강연료 push
		}

		if (!pQ.empty()) {
				// top 값을 참조하여 강연비가 가장 큰 값을 가져온다.
			res += pQ.top();
			pQ.pop();
		}
	}
	printf("%d", res);
	return 0;
}