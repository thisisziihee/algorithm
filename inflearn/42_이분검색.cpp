/*
N���� ���� ������������ ������ ���� N���� �� �� �� ���� ���� M�� �־����� 
�̺а˻����� M�� ���ĵ� ���¿��� �� ��°�� �ִ��� ���ϴ� ���α׷��� �ۼ��ϼ���.
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
int main() {
	int n, i, key, left = 0, right, mid;
	scanf("%d %d", &n, &key);
	
	std::vector<int> numArr(n);
	for (i = 0; i < n; i++) scanf("%d", &numArr[i]);
	sort(numArr.begin(), numArr.end());
	
	left = 0; right = n - 1; 
	while (left <= right) {
		mid = (left + right) / 2;
		if (numArr[mid] == key) {
			printf("%d", mid + 1);
			break;
		}
		else if (numArr[mid] > key) right = mid - 1;
		else if (numArr[mid] < key) left = mid + 1;
	}
}