/*
N���� ������ �ԷµǸ� ����� �Էµ� ���� �����ؾ� �Ѵ�.���� ������ ���ʿ� ���������� ���ʿ� �־�� �Ѵ�. ���� ���������� ���������� �������� ������ ����� �Ѵ�.
�� �Է¼��� : ù ��° �ٿ� ���� N(5<=N<=100)�� �־�����, �� ���� �ٺ��� ������ ������ ������ �־�����. ���� 0�� �Էµ��� �ʴ´�.
�� ��¼��� : ���ĵ� ����� ����Ѵ�.
*/

#include<stdio.h>



int main() {
	int n, num[101], i, j, minustemp, temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	// ��� 1 
	/*int minusIdx = 0;
	for (i = 0; i < n; i++) {
		if (num[i] < 0) {
			minustemp = num[i];
			for (j = i-1; j >= minusIdx; j--) {
				temp = j+1;
				num[temp] = num[j];
			}
			num[minusIdx] = minustemp;
			minusIdx++;
		}
	}*/


	// ��� 2 
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (num[j] > 0 && num[j + 1] < 0) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}


	for (i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
}