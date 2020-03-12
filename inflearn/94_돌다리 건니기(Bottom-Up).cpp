/*
ö���� �б��� ���µ� ������ ����������. ������ N���� ���� �ٸ��� ����� ���ҽ��ϴ�. 
ö���� �� �ٸ��� �ǳ� �� �� ���� �� ĭ �Ǵ� �� ĭ�� �ǳʶٸ鼭 ���ٸ��� �ǳ� �� �ֽ�����.
ö���� ������ �ǳʴ� ����� �� ���� �ϱ��?
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