// 10���� N�� �ԷµǸ� K������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���. ���� �ڷᱸ���� ����Ͻñ� �ٶ��ϴ�.

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
			// 16���������� 10, 11, 12, 13, 14, 15�� ���� ���ڰ� ����ϵ���
		printf("%c", str[s.top()]);
			// s.top�� ������ �ϰ� top �Լ��� ���������
		s.pop();
	}

}