/*
A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. 
DNA 순서는 A C G T 가 포함된 문자열로 나타낼 수 있다. 그 문자열은 성공적인 뉴클레오타이드 배열과 일치한다.

Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. 
각각의 뉴클레오타이드는 정수이다. A C G T는 각각 1, 2, 3, 4이다.

You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?
주어진 DNA 배열에서 뉴클레오 타이드 요소가 가장 작은 값을 찾는다.

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. 
DNA 시퀀스는 비어있지 않은 N개의 문자로 이루어진 문자열로 주어진다.

There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. 
M개의 쿼리가 있고, M개의 정수가 각각 포함된 비어있지 않은 배열 P, Q가 주어진다.

The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).
K번째 쿼리는 P[k] 부터 Q[k] 사이의 DNA 시퀀스에 포함된 뉴클레오타이드 요소 중에 가장 값이 작은 것을 찾아야 한다.

For example, consider string S = CAGCCTA and arrays P, Q such that:
	P[0] = 2    Q[0] = 4
	P[1] = 5    Q[1] = 5
	P[2] = 0    Q[2] = 6
The answers to these M = 3 queries are as follows:

The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.

Write a function: vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, 
returns an array consisting of M integers specifying the consecutive answers to all queries.
Result array should be returned as a vector of integers.

For example, given the string S = CAGCCTA and arrays P, Q such that:
	P[0] = 2    Q[0] = 4
	P[1] = 5    Q[1] = 5
	P[2] = 0    Q[2] = 6
the function should return the values [2, 4, 1], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [1..50,000];
each element of arrays P, Q is an integer within the range [0..N − 1];
P[K] ≤ Q[K], where 0 ≤ K < M;
string S consists only of upper-case English letters A, C, G, T.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	vector< vector<int> > ACGT(4, vector<int>(S.length(), 0));


	if (S[0] == 'A') ACGT[0][0] = 1;
	else if (S[0] == 'C') ACGT[1][0] = 1;
	else if (S[0] == 'G') ACGT[2][0] = 1;
	else ACGT[3][0] = 1;

	for (int i = 1; i < S.length(); i++) {
		switch (S[i])
		{
			case 'A':
				ACGT[0][i] = ACGT[0][i-1] + 1;
				ACGT[1][i] = ACGT[1][i-1];
				ACGT[2][i] = ACGT[2][i-1];
				ACGT[3][i] = ACGT[3][i - 1];
				break;
			case 'C':
				ACGT[0][i] = ACGT[0][i - 1];
				ACGT[1][i] = ACGT[1][i - 1] + 1;
				ACGT[2][i] = ACGT[2][i - 1];
				ACGT[3][i] = ACGT[3][i - 1];
				break;
			case 'G':
				ACGT[0][i] = ACGT[0][i - 1];
				ACGT[1][i] = ACGT[1][i - 1];
				ACGT[2][i] = ACGT[2][i - 1]+ 1;
				ACGT[3][i] = ACGT[3][i - 1];
				break;
			case 'T':
				ACGT[0][i] = ACGT[0][i - 1];
				ACGT[1][i] = ACGT[1][i - 1];
				ACGT[2][i] = ACGT[2][i - 1];
				ACGT[3][i] = ACGT[3][i - 1] + 1;
				break;

			default:
				break;
		}
	}

	vector<int> ans;
	int pp = 0;
	for(int i =0; i<P.size(); i++){
		for (int j = 0; j < 4; j++) {
			if (P[i] == 0) pp = 0;
			else { pp = ACGT[j][P[i] - 1]; }

			if (ACGT[j][Q[i]] > pp) {
				ans.push_back(j+1);
				break;
			}
		}
	}

	return ans;
}

int main() {
	string S;
	cin >> S;
	int M;
	cin >> M;
	vector<int> P(M, 0), Q(M, 0);
	for (int i = 0; i < M; i++) cin >> P[i];
	for (int i = 0; i < M; i++) cin >> Q[i];
	P = solution(S, P, Q);
	for (int i = 0; i < P.size(); i++) {
		cout << P[i] << " ";
	}
	return 0;
}