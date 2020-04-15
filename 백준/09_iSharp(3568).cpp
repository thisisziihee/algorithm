#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	
	vector<string> s;
	string temp = "";
	for (char ch : str) {
		if (ch == ' ' || ch == ',' || ch == ';') {
			if (temp.length() > 0) {
				s.push_back(temp);
				temp = "";
			}
		}
		else {
			temp += ch;
		}
	}
	string data_type = s[0];
	for (int i = 1; i < s.size(); i++) {
		temp = "";
		string name = "";
		for (int j = 0; j < s[i].length(); j++) {
			if (s[i][j] != '*' && s[i][j] != '&' && s[i][j] != '[' && s[i][j] != ']') {
				name += s[i][j];
			}
			else {
				if (s[i][j] == '[') temp = ']' + temp;
				else if (s[i][j] == ']') temp = '[' + temp;
				else temp = s[i][j] + temp;
			}
		}
		cout << data_type + temp + " " + name + ";" << endl;
	}
}