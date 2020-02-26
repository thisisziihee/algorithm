/*
N���� ���ҷ� ������ �ڿ��� ������ �־�����, �� ������ �� ���� �κ��������� �������� ��
�� �κ������� ������ ���� ���� ���� ��찡 �����ϸ� ��YES"�� ����ϰ�, �׷��� ������ ��NO"�� ����ϴ� ���α׷��� �ۼ��ϼ���.
���� ��� {1, 3, 5, 6, 7, 10}�� �ԷµǸ� {1, 3, 5, 7} = {6, 10} ���� �� �κ������� ���� 16���� ���� ��찡 �����ϴ� ���� �� �� �ִ�.
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int num, totalSum = 0;
int value[11];
bool flag = false;

void dfs(int index, int sum) {
	if (sum > (totalSum / 2)) return;
	if (flag == true) return;
	if (index == num + 1) {
		if (sum == totalSum - sum) {
			flag = true;
		}
	}
	else {
		dfs(index + 1, sum + value[index]);
		dfs(index + 1, sum);
	}
}

int main() {
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &value[i]);
		totalSum += value[i];
	}
	dfs(1, 0);
	if (flag == true) printf("YES");
	else printf("NO");
	return 0;
}