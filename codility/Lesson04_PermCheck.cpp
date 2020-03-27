/*
A non-empty array A consisting of N integers is given.
N개의 정수가 포함된 배열 A가 주어진다. (비어있지 않음)

A permutation is a sequence containing each element from 1 to N once, and only once.
순열은 1부터 N까지 각각의 원소가 한번씩 나온다

For example, array A such that:
	A[0] = 4
	A[1] = 1
	A[2] = 3
	A[3] = 2
is a permutation, but array A such that:

	A[0] = 4
	A[1] = 1
	A[2] = 3
is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:int solution(vector<int> &A);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.
배열 A가 주어지면, 순열을 만족하면 1 반환하고 만족하지 못하면 0 반환

For example, given array A such that:
	A[0] = 4
	A[1] = 1
	A[2] = 3
	A[3] = 2
the function should return 1.

Given array A such that:
	A[0] = 4
	A[1] = 1
	A[2] = 3
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].
*/

#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
	sort(A.begin(), A.end());
	int num = 1;
	int ans = 1;
	for (int i = 0; i < A.size(); i++) {
		if (num == A[i]) num += 1;
		else if (num != A[i] || A[i] > A.size()) {
			ans = 0;
			break;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << solution(arr) << endl;
}