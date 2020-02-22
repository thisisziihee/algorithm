/*
���� ��� �� 8���� ���ڰ� �ְ�, 3�� ��ģ ���ڰ� ���ܵȴٰ� ����. ó������ 3�� ���ڰ� 3�� ���� ���ܵȴ�. 
�̾� 6, 1, 5, 2, 8, 4�� ���ڰ� ���ʴ�� ���ܵǰ� ���������� ���� �� 7�� ���ڿ��� ���ָ� ���Ϸ����ϴ�.
N�� K�� �־��� �� ���ָ� ���Ϸ� �� ������ ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�� �Է¼��� : ù �ٿ� �ڿ��� N(5<=N<=1,000)�� K(2<=K<=9)�� �־�����.
�� ��¼��� : ù �ٿ� ������ ���� ������ ��ȣ�� ����մϴ�.
*/

#include <stdio.h>
#include <vector>

int main() {
	int n, k, i, outPrince = 0, pos = 0, cnt = 0;
	scanf("%d %d", &n, &k);

	std::vector<int> prince(n+1);

	while (true) {
		pos++;
		if (pos > n) pos = 1;
		if (prince[pos] == 0) {
			cnt++;
			if (cnt == k) {
				prince[pos] = 1;
				outPrince++;
				cnt = 0;
			}
		}
		if (outPrince == n - 1) {
			break;
		}
	}
	for (i = 1; i <= n; i++) {
		if (prince[i] == 0) { printf("%d", i); break; }
	}
}