/*
���� ��� �� 8���� ���ڰ� �ְ�, 3�� ��ģ ���ڰ� ���ܵȴٰ� ����. ó������ 3�� ���ڰ� 3�� ���� ���ܵȴ�. 
�̾� 6, 1, 5, 2, 8, 4�� ���ڰ� ���ʴ�� ���ܵǰ� ���������� ���� �� 7�� ���ڿ��� ���ָ� ���Ϸ����ϴ�.
N�� K�� �־��� �� ���ָ� ���Ϸ� �� ������ ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

// 1 ~ (K-1) ������ ���ڵ��� push_back K��° ���ڴ� pop. ��� �� �� ���� ������ �ݺ��Ѵ�.

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, k, i;

	queue<int> Q;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++) {
		Q.push(i);
	}

	while (!Q.empty()) {
			// k-1 ���� ���� �� ������ push
		for (i = 1; i < k; i++) {
			Q.push(Q.front());
			Q.pop();
		}

			// k��° ���ڴ� pop���� �����ش�.
		Q.pop();

		if (Q.size() == 1) {
			printf("%d", Q.front());
			Q.pop();
		}
	}
	return 0;
}