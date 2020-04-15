#include <bits/stdc++.h>
using namespace std;

int digit[10][7] = {
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

int main() {
	int s;
	string n;
	cin >> s >> n;
	for (int i = 0; i < 5; i++) {
		if (i == 0 || i == 2 || i == 4) {
			for (int j = 0; j < n.length(); j++) {
				int now_digit = n[j] - '0';

				// 숫자 사이의 공백
				if (j != 0) cout << " ";

				cout << " ";
				if ((i == 0 && digit[now_digit][0]) || (i == 2 && digit[now_digit][3]) || (i == 4 && digit[now_digit][6])) {
					for (int k = 0; k < s; k++) {
						cout << "-";
					}
				}
				else {
					for (int k = 0; k < s; k++) {
						cout << " ";
					}
				}
				cout << " ";
			}
			cout << endl;
		}
		else {
			for (int l = 0; l < s; l++) {
				for (int j = 0; j < n.length(); j++) {
					int now_digit = n[j] - '0';
					if (j != 0) cout << " ";

					if ((i == 1 && digit[now_digit][1]) || (i == 3 && digit[now_digit][4])) cout << "|";
					else cout << " ";

					for (int k = 0; k < s; k++) {
						cout << " ";
					}

					if ((i == 1 && digit[now_digit][2]) || (i == 3 && digit[now_digit][5])) cout << "|";
					else cout << " ";
				}
				cout << endl;
			}
		}
		
	}
}