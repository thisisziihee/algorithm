// 두 집합 A, B가 주어지면 두 집합의 교집합을 출력하는 프로그램을 작성하세요
// MS 인터뷰 문제

#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	int a, b, i, j;

	scanf("%d", &a);
	std::vector<int> aArr(a);
	for (i = 0; i < a; i++) scanf("%d", &aArr[i]);
	sort(aArr.begin(), aArr.end());

	scanf("%d", &b);
	std::vector<int> bArr(b);
	for (i = 0; i < b; i++) scanf("%d", &bArr[i]);
	sort(bArr.begin(), bArr.end());

	std::vector<int> cArr(a + b);
	int ap = 0, bp = 0, cp = 0;
	while (ap < a && bp < b) {
		if (aArr[ap] == bArr[bp]) {
			cArr[cp++] = aArr[ap++];
			bp++;
		}
		else if (aArr[ap] < bArr[bp]) {
			ap++;
		}
		else if (aArr[ap] > bArr[bp]) {
			bp++;
		}
	}

	for (i = 0; i < cp; i++) {
		printf("%d ", cArr[i]);
	}
}