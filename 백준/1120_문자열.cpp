#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int diff = str2.length() - str1.length();

	// ������ new_str1 = (str2�� �պκ�) + str1 + (str2�� �޺κ�)�̴�.
	// �׷��ٸ�, str1�� new_str1�ȿ��� ��� ��ġ�ؾ� str2�� ���� ���ڰ� ������ Ȯ���ϴ� ������ �ȴ�.
	
	int cnt = 0;
	int ans = -1;

	for (int start = 0; start <= diff; start++) {
		cnt = 0;
		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] != str2[start + i]) cnt += 1;
		}
		if (ans == -1 || ans > cnt) ans = cnt;
	}
	cout << ans << endl;
}