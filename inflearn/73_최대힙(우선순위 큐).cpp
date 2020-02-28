/*
�ִ����� ��������Ʈ���� ������ �ڷᱸ���Դϴ�. �� ������ �θ� ��尪�� �����ڽİ� ������ �ڽĳ���� ������ ũ�� Ʈ���� �����ϴ� ���Դϴ�. 
�׷��� �ϸ� Ʈ���� ��Ʈ(root)���� �Էµ� ���� �� ���� ū ���� ����Ǿ� �ֽ��ϴ�. 

�ִ��� �ڷḦ �̿��Ͽ� ������ ���� ������ �ϴ� ���α׷��� �ۼ��ϼ���.
1) �ڿ����� �ԷµǸ� �ִ����� �Է��Ѵ�.
2) ���� 0 �� �ԷµǸ� �ִ������� �ִ��� ������ ����Ѵ�. (����� �ڷᰡ ������ -1�� ����Ѵ�.)
3) -1�� �ԷµǸ� ���α׷� �����Ѵ�.
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
					// top() : root �� ����
				printf(">>%d\n", pQ.top());
				pQ.pop();
			}
		}
		else {
				//priority_queue ������ ���� �ڵ����� �켱���� ť ���·� ������ش�.
			pQ.push(a);
		}
	}
}