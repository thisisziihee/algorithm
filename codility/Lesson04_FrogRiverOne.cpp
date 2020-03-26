/*
A small frog wants to get to the other side of a river. 
The frog is initially located on one bank of the river (position 0) and wants to get to the opposite bank (position X+1). 
개구리는 0에서 시작. 반대편으로 가고 싶어함 (X+1 위치)

Leaves fall from a tree onto the surface of the river.
나무에서 나뭇잎들이 강 위로 떨어진다.

You are given an array A consisting of N integers representing the falling leaves. 
떨어지는 나뭇잎들을 나타내는 정수 N들의 배열 A

A[K] represents the position where one leaf falls at time K, measured in seconds.
A[K]는 K초에 떨어진 나뭇잎의 위치이다.

The goal is to find the earliest time when the frog can jump to the other side of the river. 
목표는 개구리가 강 반대편으로 건널 수 있는 가장 빠른 시간을 찾는 것이다.

The frog can cross only when leaves appear at every position across the river from 1 to X 
개구리는 1부터 X까지의 나뭇잎이 나타날 때 건널 수 있다. 

(that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves). 
나뭇잎으로 커버된 1부터 X까지의 모든 나뭇잎을 발견하는 가장 빠른 순간을 찾아야한다.

You may assume that the speed of the current in the river is negligibly small, i.e. the leaves do not change their positions once they fall in the river.
나뭇잎은 위치 안바뀌고 강의 스피드는 엄청 낮아서 무시 가능

For example, you are given integer X = 5 and array A such that:
  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.

Write a function: int solution(int X, vector<int> &A);
that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog can jump to the other side of the river.

If the frog is never able to jump to the other side of the river, the function should return −1.
For example, given X = 5 and array A such that:
  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and X are integers within the range [1..100,000];
each element of array A is an integer within the range [1..X].
*/

#include <bits/stdc++.h>
using namespace std;

int solution(int X, vector<int> &A) {
	vector<int> check(X+1, 0);
	int cnt = 0;
	for (int i = 0; i < A.size(); i++) {
		if (check[A[i]] == 0) {
			cnt += 1;
			check[A[i]] += 1;
		}
		if (cnt == X) return i;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int x; 
	cin >> x;
	cout << solution(x, arr) << endl;
	return 0;
}