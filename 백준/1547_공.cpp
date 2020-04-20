#include <iostream>

using namespace std;

bool ball[4] = { false };

int main() {
	int n, a, b;
	cin >> n;
	ball[1] = true;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (ball[a] == true) {
			ball[a] = false;
			ball[b] = true;
		}
		else if (ball[b] == true) {
			ball[b] = false;
			ball[a] = true;
		}
	}

	for (int i = 1; i <= 3; i++) {
		if (ball[i]) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}