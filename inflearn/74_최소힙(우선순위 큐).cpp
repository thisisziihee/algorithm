/*
최소힙은 완전이진트리로 구현된 자료구조입니다. 그 구성은 부모 노드값이 왼쪽자식과 오른쪽 자식노드의 값보다 작게 트리를 구성하는 것입니다.
그렇게 하면 트리의 루트(root)노드는 입력된 값들 중 가장 작은 값이 저장되어 있습니다.

최소힙 자료를 이용하여 다음과 같은 연산을 하는 프로그램을 작성하세요.
1) 자연수가 입력되면 최소힙에 입력한다.
2) 숫자 0 이 입력되면 최소힙에서 최댓값을 꺼내어 출력한다. (출력할 자료가 없으면 -1를 출력한다.)
3) -1이 입력되면 프로그램 종료한다.
*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int value;

	priority_queue<int> pQ;

	while (true) {
		scanf("%d", &value);
		if (value == -1) { break; }
		else if (value == 0) {
			if (pQ.empty() == true) {
				printf("-1\n");
			}
			else {
				printf("%d\n", -pQ.top());
				pQ.pop();
			}
		}
		else {
			// 원래 값에 -를 붙여 push한다.
			// 그러면 실제 값이 가장 작은 수가 root를 차지한다.
			// pop하여 가져올 때에만 다시 -를 붙여 실제 값으로 출력되게 한다.
			pQ.push(-value);
		}
	}
}