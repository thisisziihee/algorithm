/*
You are given N counters, initially set to 0, and you have two possible operations on them:
N counter가 주어지고, 0으로 초기화된다. 두 가지 연산이 가능하다.

increase(X) − counter X is increased by 1,
counter X는 1씩 증가
max counter − all counters are set to the maximum value of any counter. 
모든 counter들의 값이 최댓값으로 변한다.

A non-empty array A of M integers is given. This array represents consecutive operations:
비어있지 않은 M개의 정수 배열 A가 주어지면, 이 배열은 연이은 연산을 나타낸다.

if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
A[K] == X이라면, K는 increase(X) 연산을 한다.  X위치의 값을 1증가

if A[K] = N + 1 then operation K is max counter.
A[K] == N+1 이라면, K는 max counter 연산을 한다.

// 3 4 4 6 1 4 4

For example, given integer N = 5 and array A such that:
	A[0] = 3
	A[1] = 4
	A[2] = 4
	A[3] = 6
	A[4] = 1
	A[5] = 4
	A[6] = 4
the values of the counters after each consecutive operation will be:
	(0, 0, 1, 0, 0)
	(0, 0, 1, 1, 0)
	(0, 0, 1, 2, 0)
	(2, 2, 2, 2, 2)
	(3, 2, 2, 2, 2)
	(3, 2, 2, 3, 2)
	(3, 2, 2, 4, 2)

The goal is to calculate the value of every counter after all operations.

Write a function: vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers representing the values of the counters.
정수 N, 비어있지 않은 M개의 정수 배열 A가 주어지면, counter 값을 담은 배열 반환
Result array should be returned as a vector of integers.

For example, given:
	A[0] = 3
	A[1] = 4
	A[2] = 4
	A[3] = 6
	A[4] = 1
	A[5] = 4
	A[6] = 4
the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:
N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> res;

vector<int> solution(int N, vector<int> &A) {
	res = vector<int> (N, 0);
	int maxx = 0;
	int last_max_value = 0;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == N + 1) last_max_value = maxx;
		else {
			if (res[A[i] - 1] < last_max_value) res[A[i] - 1] = last_max_value + 1;
			else res[A[i] - 1] += 1;

			if (res[A[i] - 1] > maxx) maxx = res[A[i] - 1];
		}
	}

	for (int i = 0; i < N; i++) {
		if (res[i] < last_max_value) res[i] = last_max_value;
	}

	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	cin >> m;
	vector<int> arr(m, 0);
	for (int i = 0; i < m; i++) cin >> arr[i];
	arr = solution(n, arr);
	cout << endl << endl << endl << endl << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}