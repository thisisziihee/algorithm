#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <set>

using namespace std;

long long s, t;
const long long limit = 1000000000LL;

int main() {
	cin >> s >> t;
	
	// 동일한 숫자에 대해서 4가지 연산이 계속 일어나 무한루프에 빠지지 않도록 함
	set<long long> check;
	check.insert(s);

	// 연산을 통한 결과값과 연산순서를 담은 문자열
	queue< pair<long long, string> > Q;
	Q.push(make_pair(s, ""));

	while (!Q.empty()) {
		long long x = Q.front().first;
		string temp = Q.front().second;
		Q.pop();
		if (x == t) {
			if (temp.length() == 0) {
				temp = "0";
			}
			cout << temp << endl;
			return 0;
		}

		// 길이가 같다면 사전 순으로 출력되어야 하므로, *, +, -, / 순서로 if문 진행한다.
		if (x*x >= 0 && x*x <= limit && check.count(x*x) == 0) {
			Q.push(make_pair(x*x, temp + "*"));
			check.insert(x*x);
		}
		if (x + x >= 0 && x + x <= limit && check.count(x + x) == 0) {
			Q.push(make_pair(x + x, temp + "+"));
			check.insert(x + x);
		}
		if (x - x >= 0 && x - x <= limit && check.count(x - x) == 0) {
			Q.push(make_pair(x - x, temp + "-"));
			check.insert(x - x);
		}
		if (x != 0 && x / x >= 0 && x / x <= limit && check.count(x / x) == 0) {
			Q.push(make_pair(x / x, temp + "/"));
			check.insert(x / x);
		}
	}
	cout << "-1" << endl;
	return 0;
}