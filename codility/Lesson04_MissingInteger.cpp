/*
This is a demo task.

Write a function: int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
N 개의 정수를 담은 배열 A가 주어지면, A배열에는 없는 가장 작은 양수를 반환하라

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
	int res = 1;
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());

	for (int i = 0; i < A.size(); i++) {
		if (A[i] < res) continue;
		else if (A[i] == res) res += 1;
		else if (A[i] > res) break;
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << solution(arr) << endl;
	return 0;
}