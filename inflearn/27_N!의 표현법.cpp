/*
������ N�� ���Ͽ� N!�� �Ҽ����� ������ ǥ���ϴ� ����� �ִ�. 
���� ��� 825�� (0 1 2 0 1)�� ǥ���� �����ѵ�, �̴� 2�� ���� 3�� 1��, 5�� 2��, 7�� ����, 11�� 1���� ���̶�� �ǹ��̴�. 
101���� ���� ������ N�� ���Ͽ� N ���丮���� �̿� ���� ǥ������� ��ȯ�ϴ� ���α׷��� �ۼ��غ���. 
*/

#include<stdio.h>
#include<vector>

int main() {
	int n, i, j, temp;
	scanf("%d", &n);
	
	std::vector<int> check(n + 1);

		// ���μ����� ���
		// ���� ���丮���� �� ����� ���Ŀ� ���μ����� �������� for�� ������ ���μ�����
	for (i = 2; i <= n; i++) {
		temp = i;
		j = 2;
		while (true) {
			if (temp%j == 0) {
				temp = temp / j;
				check[j]++;
			}
			else j++;
			
			if (temp == 1)break;
		}
	}
	printf("%d! = ", n);
	for (i = 2; i <= n; i++) {
		if (check[i] > 0) {
			printf("%d ", check[i]);
		}
	}
}

