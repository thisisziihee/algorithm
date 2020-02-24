/*
A도시에서 출발한 기차는 B도시로 도착한다. 그런데 도로 중간에 T자형 교차로가 있어 출발한 기차의 도착 순서를 조정할 수 있다.
교차로에서는 다음과 같은 두 개의 작업을 합니다.
P(push)작업 : A도시에서 오는 기차를 교차로에 넣는다.
O(out)작업 : 교차로에 들어온 가장 최근 기차를 B도시로 보낸다.

만약 2 1 3 기차 번호 순으로 A도시에서 출발하더라도 B도시에는 T교차로를 이용하여 1 2 3 순으로 도착하게 할 수 있습니다.
그 작업 P, P, O, O, P, O순으로 작업을 하면 B도시에 1, 2, 3 순으로 도착합니다.

1부터 N까지 번호를 가진 기차가 A도시에서 어떤 순으로 출발하든, B도시에 번호순으로 도착하도록 하는 교차로 작업을 출력합니다. 
모든 기차는 교차로에 들어가야만 B도시로 갈 수 있습니다. 번호순서대로 도착이 불가능하면 impossible 이라고 출력합니다.
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main() {
	int n, train, i;
	scanf("%d", &n);

	stack <int> s;		//교차로 스택
	vector<char> str;	// POP, PUSH 작업을 출력하기 위한 캐릭터 배열

	int temp;
	int j = 1;	// 기차가 오름차순으로 들어오는지 확인하기위한 변수
	for (i = 1; i <= n; i++) {
		scanf("%d", &temp);
			// A도시로 들어온 기차 푸쉬
		s.push(temp);
		str.push_back('P');

		while (true) {
				// 더 이상 꺼낼 기차가 없는 경우
			if (s.empty()) break;
				// 스택에서 꺼내온 기차 번호가 오름차순 조건을 만족한 경우
			if (j == s.top()) {
				j++;
				s.pop();
				str.push_back('O');
			}
			else {
				break;
			}
		}
	}
		// 오름차순으로 정렬되지 않아서 아직 스택에 기차가 남아있는 경우
	if (!s.empty()) {
		printf("impossible");
	}
	else {
		for (i = 0; i < str.size(); i++) {
			printf("%c", str[i]);
		}
	}
}