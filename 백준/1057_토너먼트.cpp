#include <iostream>

using namespace std;

int n, a, b;

int sol(int a, int b) {
	int round = 1, first = a, second = b;
	if (a > b) {
		first = b;
		second = a;
	}
	while (first >= 1 && second >= 1) {
		if (second - first == 1 && first % 2 == 1 && second % 2 == 0) {
			return round;
		}

		if (first % 2 == 1) first = (first / 2) + 1;
		else first = first / 2;

		if (second % 2 == 1) second = (second / 2) + 1;
		else second = second / 2;

		round += 1;
	}
	return -1;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	cout << sol(a, b) << endl;
}