/*
ĳ���� ũ�Ⱑ �־�����, ĳ�ð� ����ִ� ���¿��� N���� �۾��� CPU�� ���ʷ� ó���Ѵٸ�
N���� �۾��� ó���� �� ĳ�ø޸��� ���¸� ���� �ֱ� ���� �۾����� ���ʴ�� ����ϴ� ���α׷��� �ۼ��ϼ���.
�� �Է¼��� : ù ��° �ٿ� ĳ���� ũ���� S(3<=S<=10)�� �۾��� ���� N(5<=N<=1,000)�� �Էµȴ�.
			  �� ��° �ٿ� N���� �۾���ȣ�� ó�������� �־�����. �۾���ȣ�� 1 ~100 �̴�.
�� ��¼��� : ������ �۾� �� ĳ�ø޸��� ���¸� ���� �ֱ� ���� �۾����� ���ʷ� ����մϴ�.
*/
#include<stdio.h>
int main() {
	int cacheSize, n, num, i, j, cacheIndex;
	int cache[11] = { 0, };
	scanf("%d %d", &cacheSize, &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);

		cacheIndex = -1;
		for (j = 0; j < cacheSize; j++) {
			if (num == cache[j]) { cacheIndex = j; }
		}

		// �� �߰�, ĳ�ð� ������ �� �� ���� ���� ���� ����(ĳ�� �̽�)
		if (cacheIndex == -1) {
			for (j = cacheSize -1; j >= 0; j--) {
				cache[j] = cache[j-1];
			}
		}

		// �Է��� �۾� ��ȣ�� ĳ�ÿ� �ִ� ��� 
		else if (cacheIndex > -1) {
			for (j = cacheIndex; j >= 0; j--) {
				cache[j] = cache[j-1];
			}
		}
		cache[0] = num;
	}
	for (j = 0; j < cacheSize; j++) {
		printf("%d ", cache[j]);
	}
}