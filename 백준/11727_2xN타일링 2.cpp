/*
2��n ���簢���� 2��1�� 2��2 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n�� �־�����. (1 �� n �� 1,000)
���
ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> dy(n + 1, 0);
	dy[1] = 1;
	dy[2] = 3;
	for (int i = 3; i <= n; i++) {
		dy[i] = (dy[i - 2] * 2 + dy[i - 1])%10007;
	}
	cout << dy[n] << endl;
	return 0;
}