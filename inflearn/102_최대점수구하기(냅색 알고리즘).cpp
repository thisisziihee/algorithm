/*
이번 정보올림피아드대회에서 좋은 성적을 내기 위하여 현수는 선생님이 주신 N개의 문제를 풀려고 합니다. 
각 문제는 그것을 풀었을 때 얻는 점수와 푸는데 걸리는 시간이 주어지게 됩니다. 

제한시간 M안에 N개의 문제 중 최대점수를 얻을 수 있도록 해야 합니다. 
(해당문제는 해당시간이 걸리면 푸는 걸로 간주한다, 한 유형당 한개만 풀 수 있습니다.)

▣ 입력설명
첫 번째 줄에 문제의 개수N(1<=N<=100)과 제한 시간 M(10<=M<=1000)이 주어집니다.
두 번째 줄부터 N줄에 걸쳐 문제를 풀었을 때의 점수와 푸는데 걸리는 시간이 주어집니다.

▣ 출력설명
첫 번째 줄에 제한 시간안에 얻을 수 있는 최대 점수를 출력합니다.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	int score, time;

	// 한 문제당 한 번만 풀 수 있으므로 (문제 수 * 제한 시간) 의 크기로 배열을 선언해야한다.
	// dy[i][j] : 문제 i번째까지에서 j시간 안에 얻을 수 있는 최대 점수
	vector< vector<int> > dy(n + 1, vector<int>(m + 1));

	// 이차원 배열로 하면 값이 커지는 경우 시간 초과를 막기 위해서 일차원 배열로 함
	// j를 j - time 부터 시작하면 무조건 값이 중복이 되어서 한 문제를 여러 번 풀게 되므로 뒤에서부터 풀기 시작
	// 뒤에서 부터 시작하고 0으로 초기화한 앞에 있는 값을 참조하니까 중복 피할 수 있음
	vector<int> dyy(m + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> score >> time;
		for (int j = m; j >= time; j--) {
			dy[i][j] = max(dy[i][j], dy[i - 1][j - time] + score);
			dyy[j] = max(dyy[j], dyy[j - time] + score);
		}
		if(i != n) copy(dy[i].begin(), dy[i].end(), dy[i + 1].begin());
	}

	cout << dy[n][m] << endl;
	cout << dyy[m] << endl;
	return 0;
}