#include<iostream>
#include <queue>

using namespace std;

queue<int> arr;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) arr.push(i + 1);

	while (arr.size() != 1) {
		arr.pop();
		if (arr.size() == 1) break;
		arr.push(arr.front());
		arr.pop();
	}
	cout << arr.front() << endl;
	return 0;
}