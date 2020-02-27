/*
N���� ���ڰ� �ԷµǸ� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���. �����ϴ� ����� ���������Դϴ�.
*/
#include<stdio.h>

int data[10], temp[10];

void divide(int left, int right) {
	int mid, p1, p2, p3;
	if (left < right) {
		mid = (left + right) / 2;
		divide(left, mid);
		divide(mid + 1, right);
		p1 = left;
		p2 = mid + 1;
		p3 = left;
		while (p1 <= mid && p2 <= right) {
			if (data[p1] < data[p2]) temp[p3++] = data[p1++];
			else temp[p3++] = data[p2++];
		}
			// ���� while���� ��ġ�� ������ ���ۿ� �����ִ� ���� ó��
		while (p1 <= mid) temp[p3++] = data[p1++];
		while (p2 <= right) temp[p3++] = data[p2++];
	}
}

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &data[i]);
	}
		// �ε��� 1���� n���� ����
	divide(1, n);
	for (i = 1; i <= n; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}