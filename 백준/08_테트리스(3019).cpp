#include<bits/stdc++.h>
using namespace std;

int c, p;
vector<int> arr;

// i��° ĭ�� str ���¸� ������ Ȯ��
// str ���´� �ش� ���� �� ���´� ����
int check(int i, string str) {
	// 1. i��° ĭ�� ���� ������ ���� ����� ���
	if (i + str.length() > c)return 0;

	int base = arr[i] - (str[0] - '0');

	for (int j = 0; j < str.length(); j++) {
		if (base != arr[i + j] - (str[j] - '0')) return 0;
	}
	return 1;
}


int main() {
	cin >> c >> p;
	
	arr = vector<int> (c, 0);
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int i = 0; i < c; i++) {
		// �� p�� ȸ������ ��, �������� �� �ִ� ���¸� ���ڿ� ���·� check�Լ��� ����
		// i��° ĭ�� ���ڿ��� ���� ���¸� ������ 1 ��ȯ��
		if (p == 1) ans += check(i, "0") + check(i, "0000");
		else if (p == 2) ans += check(i, "00");
		else if (p == 3) ans += check(i, "001") + check(i, "10");
		else if (p == 4) ans += check(i, "100") + check(i, "01");
		else if (p == 5) ans += check(i, "000") + check(i, "01") + check(i, "10") + check(i, "101");
		else if (p == 6) ans += check(i, "000") + check(i, "00") + check(i, "20") + check(i, "011");
		else if (p == 7) ans += check(i, "000") + check(i, "02") + check(i, "110") + check(i, "00");
	}
	cout << ans << endl;
}