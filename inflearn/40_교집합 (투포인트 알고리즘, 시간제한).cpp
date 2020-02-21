// �� ���� A, B�� �־����� �� ������ �������� ����ϴ� ���α׷��� �ۼ��ϼ���
// MS ���ͺ� ����

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