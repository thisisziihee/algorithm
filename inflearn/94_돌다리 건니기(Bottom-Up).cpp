/*
철수는 학교에 가는데 개울을 만났습ㄴ디ㅏ. 개울은 N개의 돌로 다리를 만들어 놓았습니다. 
철수는 돌 다리를 건널 때 한 번에 한 칸 또는 두 칸씩 건너뛰면서 돌다리를 건널 수 있습ㄴ다.
철수가 개울을 건너는 방법은 몇 가지 일까요?
*/

#include<bits/stdc++.h>

using namespace std;

int stone_bridge[100];

int dfs(int n) {
	if (stone_bridge[n] != 0) return stone_bridge[n];
	else return stone_bridge[n] = dfs(n - 1) + dfs(n - 2);
}

int main() {
	int n;
	cin >> n;
	stone_bridge[1] = 1;
	stone_bridge[2] = 2;
	dfs(n+1);
	cout << stone_bridge[n+1];
}