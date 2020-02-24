/*
괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main() {
	char str[31];
	scanf("%s", &str);

	stack<char> s;
	int i, flag = 1;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.empty() == true) {
				printf("NO");
				flag = 0;
				break;
			}
			s.top();
			s.pop();
		}
	}
	if(flag == 1 && s.empty()) printf("YES");
	else if (flag == 1 && !s.empty()) printf("NO");
	return 0;
}
