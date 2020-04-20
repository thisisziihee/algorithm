#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int diff = str2.length() - str1.length();

	// 어차피 new_str1 = (str2의 앞부분) + str1 + (str2의 뒷부분)이다.
	// 그렇다면, str1이 new_str1안에서 어디에 위치해야 str2와 같은 글자가 많은지 확인하는 문제가 된다.
	
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