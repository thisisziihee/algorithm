/*
Write a function: int solution(int A, int B, int K);

that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:
세 개의 정수 A, B, K가 주어지면, A부터 B까지의 정수를 K로 나눌 수 있는 수의 개수를 반환한다.

{ i : A ≤ i ≤ B, i mod K = 0 }

For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

Write an efficient algorithm for the following assumptions:
A and B are integers within the range [0..2,000,000,000];
K is an integer within the range [1..2,000,000,000];
A ≤ B.
*/

#include <bits/stdc++.h>

using namespace std;

int solution(int A, int B, int K) {
	if (A == 0 && B == 0) return 1;
	else if (A == 0) return (floor(B / K)) + 1;
	else {
		int bb = floor(B / K);
		int aa = floor(A / K);
		if (A%K == 0) return bb - aa + 1;
		else return bb - aa;
	}
}

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	cout << solution(a, b, k) << endl;
	return 0;
}