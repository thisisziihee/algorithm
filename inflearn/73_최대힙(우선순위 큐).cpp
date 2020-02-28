/*
최대힙은 완전이진트리로 구현된 자료구조입니다. 그 구성은 부모 노드값이 왼쪽자식과 오른쪽 자식노드의 값보다 크게 트리를 구성하는 것입니다. 
그렇게 하면 트리의 루트(root)노드는 입력된 값들 중 가장 큰 값이 저장되어 있습니다. 

최대힙 자료를 이용하여 다음과 같은 연산을 하는 프로그램을 작성하세요.
1) 자연수가 입력되면 최대힙에 입력한다.
2) 숫자 0 이 입력되면 최대힙에서 최댓값을 꺼내어 출력한다. (출력할 자료가 없으면 -1를 출력한다.)
3) -1이 입력되면 프로그램 종료한다.
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int a;
	priority_queue<int> pQ;
	while (true) {
		scanf("%d", &a);
		if (a == -1) break;
		else if (a == 0) {
			if (pQ.empty() == 1) printf(">>-1\n");
			else {
					// top() : root 값 참조
				printf(">>%d\n", pQ.top());
				pQ.pop();
			}
		}
		else {
				//priority_queue 구조에 의해 자동으로 우선순위 큐 형태로 만들어준다.
			pQ.push(a);
		}
	}
}