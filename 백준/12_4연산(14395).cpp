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
	
	// ������ ���ڿ� ���ؼ� 4���� ������ ��� �Ͼ ���ѷ����� ������ �ʵ��� ��
	set<long long> check;
	check.insert(s);

	// ������ ���� ������� ��������� ���� ���ڿ�
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

		// ���̰� ���ٸ� ���� ������ ��µǾ�� �ϹǷ�, *, +, -, / ������ if�� �����Ѵ�.
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