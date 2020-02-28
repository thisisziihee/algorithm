/*
������ ������ �������̴�. N���� ������� ���� ��û�� �ؿԴ�. �� ����� D�� �ȿ� �ͼ� ������ �� �ָ� M��ŭ�� �����Ḧ �ֱ�� �ߴ�.
�� ����� ��û�� D�� M�� �������� ���� ���� ���� �� �� �ֵ��� ���� �������� ¥�� �Ѵ�.
�� ������ Ư���� ������ �Ϸ翡 �ϳ��� ��������� ������ �� �� �ִ�.
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Data {
	int money;
	int when;
	Data(int a, int b) {
		money = a;
		when = b;
	}
	bool operator < (Data &b) {
		return when > b.when;
	}
};


int main() {
	int n, i, j, m, d, res = 0, max = -2147000000;

	vector <Data> T;			// ���� �������Ѱ� �����ῡ ���� ����ü Data �������� �� ���� T
	priority_queue<int> pQ;		// �ش� ��¥�� �� �� �ִ� ������ �����Ḧ ���� �켱���� ť pQ
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &m, &d);
		T.push_back(Data(m, d));
		if (d > max) max = d;
	}

	sort(T.begin(), T.end());	// ���� ��¥�� �������� �������� ���� ( Data ����ü���� ������ < �����ڿ� ����)

	j = 0;
	for (i = max; i >= 1; i--) { // ������ ���� ��¥���� ������������ �����층

		for (; j < n; j++) {	 // i�Ͽ� �� �� �ִ� ���� ã��

			if (T[j].when < i) break;	// �������� i�Ϻ��� �� ���� ���������� ���� ��쿡�� break
			pQ.push(T[j].money);		// i ������¥���� ũ�ų� ���� ������ ������ push
		}

		if (!pQ.empty()) {
				// top ���� �����Ͽ� ������ ���� ū ���� �����´�.
			res += pQ.top();
			pQ.pop();
		}
	}
	printf("%d", res);
	return 0;
}