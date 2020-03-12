/*
N���� �ڿ����� �̷���� ������ �־����� ��, �� �߿��� ���� ��� �����ϴ� ���ҵ��� ������ ã�� ���α׷��� �ۼ��϶�.
�������, ���Ұ� 2, 7, 5, 8, 6, 4, 7, 12, 3�̸� ���� ��� �����ϴ� ���ҵ��� �̾Ƴ��� 
2, 5, 6, 7, 12�� �̾Ƴ��� ���̰� 5�� �ִ� �κ� ���� ������ ���� �� �ִ�.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, num;
	cin >> n;
	vector<int> num_arr(n + 1), dy(n + 1);
	// dy_table[i] : ������� �ϴ� ���������� ������ ���� i��° �����̸鼭 ���� �� ���̸� ���� ������ ����

	for (int i = 0; i < n; i++) cin >> num_arr[i];
	
	dy[1] = 1;
	int temp;
	// ������ ���� num_arr[i]�� ���� �ִ� �κ� ���� ����
	for (int i = 2; i <= n; i++) {
		dy[i] = 1;
		for (int j = i - 1; j > 0; j--) {
			if (num_arr[j] < num_arr[i]) {
				temp = dy[j] + 1;
				dy[i] = (dy[i] > temp ? dy[i] : temp);
			}
		}
	}
	cout << *max_element(dy.begin(), dy.end());
	return 0;
}