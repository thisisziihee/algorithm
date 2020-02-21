/*
N개의 수를 오름차순으로 정렬한 다음 N개의 수 중 한 개의 수인 M이 주어지면 
이분검색으로 M이 정렬된 상태에서 몇 번째에 있는지 구하는 프로그램을 작성하세요.
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