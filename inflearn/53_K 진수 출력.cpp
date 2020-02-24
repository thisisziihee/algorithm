// 10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요. 스택 자료구조를 사용하시기 바랍니다.

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main() {
	int n, k, temp;
	scanf("%d %d", &n, &k);
	
	stack<int> s;

	while (n > 0) {
		temp = n % k;
		n = n / k;
		s.push(temp);
	}

	char str[20] = "0123456789ABCDEF";
	while (!s.empty()) {
			// 16진수에서의 10, 11, 12, 13, 14, 15에 대한 문자값 출력하도록
		printf("%c", str[s.top()]);
			// s.top는 참조만 하고 top 함수로 빼내줘야함
		s.pop();
	}

}