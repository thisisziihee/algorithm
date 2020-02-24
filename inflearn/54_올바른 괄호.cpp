/*
��ȣ�� �ԷµǸ� �ùٸ� ��ȣ�̸� ��YES", �ùٸ��� ������ ��NO"�� ����մϴ�.
(())() �̰��� ��ȣ�� ���� �ùٸ��� ��ġ�ϴ� ������, (()()))�� �ùٸ� ��ȣ�� �ƴϴ�.
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
