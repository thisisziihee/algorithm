/*
N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요. 정렬하는 방법은 병합정렬입니다.
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
			// 위의 while문을 마치고 나오면 버퍼에 남아있는 원소 처리
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
		// 인덱스 1부터 n까지 정렬
	divide(1, n);
	for (i = 1; i <= n; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}