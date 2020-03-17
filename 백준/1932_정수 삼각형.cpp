/*
		7
	  3   8
	8   1   0
  2   7   4   4
4   5   2   6   5
�� �׸��� ũ�Ⱑ 5�� ���� �ﰢ���� �� ����̴�.
�� ���� 7���� �����ؼ� �Ʒ��� �ִ� �� �� �ϳ��� �����Ͽ� �Ʒ������� ������ ��, �������� ���õ� ���� ���� �ִ밡 �Ǵ� ��θ� ���ϴ� ���α׷��� �ۼ��϶�. 
�Ʒ����� �ִ� ���� ���� ������ ���õ� ���� �밢�� ���� �Ǵ� �밢�� �����ʿ� �ִ� �� �߿����� ������ �� �ִ�.
�ﰢ���� ũ��� 1 �̻� 500 �����̴�. �ﰢ���� �̷�� �ִ� �� ���� ��� �����̸�, ������ 0 �̻� 9999 �����̴�.

�Է� : ù° �ٿ� �ﰢ���� ũ�� n(1 �� n �� 500)�� �־�����, ��° �ٺ��� n+1��° �ٱ��� ���� �ﰢ���� �־�����.

��� : ù° �ٿ� ���� �ִ밡 �Ǵ� ��ο� �ִ� ���� ���� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	vector< vector<int> > triangle;
	vector< vector<int> > dy;

	vector<int> temp;
	int i, j;
	for (i = 1; i <= n; i++) {
		temp = vector<int>(i, 0);
		dy.push_back(temp);
		temp.clear();
		while (true) {
			cin >> j;
			temp.push_back(j);
			if (temp.size() == i) {
				triangle.push_back(temp);
				break;
			}
		}
	}
	dy[0][0] = triangle[0][0];

	int maxx = 0;
	for (i = 1; i < triangle.size(); i++) {
		for (j = 0; j < triangle[i].size(); j++) {
			if (j >= 1 && j < triangle[i - 1].size()) {
				dy[i][j] = max(dy[i - 1][j - 1], dy[i - 1][j]) + triangle[i][j];
			}
			else if (j == dy[i - 1].size() && j >= 1) {
				dy[i][j] = dy[i - 1][j - 1] + triangle[i][j];
			}
			else if( j < 1 && j < triangle[i - 1].size() ){
				dy[i][j] = dy[i - 1][j] + triangle[i][j];
			}
			if (maxx < dy[i][j]) maxx = dy[i][j];
		}
	}

	cout << maxx << endl;
	return 0;
}