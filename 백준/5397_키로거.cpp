#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;
	
	stack<char> res;
	stack<char> tmp;

	while (tc--) {
		string temp = "";
		cin >> temp;
	

		for (int i = 0; i < temp.length(); i++) {
			if ((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z') || (temp[i] >= '0' && temp[i] <= '9')) res.push(temp[i]);

			else if (temp[i] == '>' && !tmp.empty()) {
				res.push(tmp.top());
				tmp.pop();
			}
			else if (temp[i] == '<' && !res.empty()) {
				tmp.push(res.top());
				res.pop();
			}
			else if (temp[i] == '-' && !res.empty()) res.pop();
		}

		while (!res.empty()) {
			tmp.push(res.top());
			res.pop();
		}
		while (!tmp.empty()) {
			cout << tmp.top();
			tmp.pop();
		}
		cout << '\n';
	}
}