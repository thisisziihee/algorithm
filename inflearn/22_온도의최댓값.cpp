/*
���� ������ �µ��� ������ ������ �־����� ��, �������� ��ĥ ������ �µ��� ���� ���� ū���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include<stdio.h>
#include<vector>
int main() {
	int n, k, i;
	scanf("%d %d", &n, &k);
	std::vector <int> a(n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int max; int sum = 0;
	for (i = 0; i < k; i++) { sum += a[i]; }
	max = sum;

		// [i-k] ���� ���� [i]���� ���ؼ� k�� ���� ����
		// ���� for�� ���� �ð����⵵ n���� �ذ��� �� �ִ�.
	for (i = k; i < n; i++) {
		sum = sum + (a[i] - a[i-k] );
		max = (sum > max ? sum : max);
	}
	printf("%d", max);
}