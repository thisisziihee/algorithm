// ���� ���� : i�� 0�� �ƴ϶� 1���� ����. 0~i���� ������ a[i]�� �� �˸��� ��ġ�� ����
#include<stdio.h>

int main() {
	int n, num[101], i, j, temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &num[i]);

	for (i = 1; i < n; i++) {
		temp = num[i];
		for (j = i - 1; j >= 0; j--) {
			if (num[j] > temp) {
					// temp���� ū ���� ���������� �з���.
				num[j + 1] = num[j];
			}
				// temp ���� ū ���� �����ϱ� j+1 ��ġ�� temp ����
				// j+1�� �ִ� ���� j+2 ���� �Ű����ų�, temp�� i�ڸ��� ���Ե�
			else break;
		}
		num[j + 1] = temp;
	}

	for (i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
}