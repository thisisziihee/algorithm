#include<bits/stdc++.h>
using namespace std;

int c, p;
vector<int> arr;

// i번째 칸에 str 형태를 갖는지 확인
// str 형태는 해당 블럭이 딱 들어맞는 형태
int check(int i, string str) {
	// 1. i번째 칸에 블럭을 놓으면 범위 벗어나는 경우
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
		// 블럭 p를 회전했을 때, 끼워맞출 수 있는 형태를 문자열 형태로 check함수에 전달
		// i번째 칸이 문자열과 같은 형태를 가지면 1 반환됨
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