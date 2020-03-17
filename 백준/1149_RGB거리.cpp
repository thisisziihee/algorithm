/*
RGB�Ÿ����� ���� N�� �ִ�. �Ÿ��� �������� ��Ÿ�� �� �ְ�, 1�� ������ N�� ���� ������� �ִ�.
���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�. 
������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��, �Ʒ� ��Ģ�� �����ϸ鼭 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���غ���.

1. 1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
2. N�� ���� ���� N-1�� ���� ���� ���� �ʾƾ� �Ѵ�.
3. i(2 �� i �� N-1)�� ���� ���� i-1��, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.

�Է�
ù° �ٿ� ���� �� N(2 �� N �� 1,000)�� �־�����. 
��° �ٺ��� N���� �ٿ��� �� ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� 1�� ������ �� �ٿ� �ϳ��� �־�����. 
���� ĥ�ϴ� ����� 1,000���� �۰ų� ���� �ڿ����̴�.

��� : ù° �ٿ� ��� ���� ĥ�ϴ� ����� �ּڰ��� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector< vector<int> > house(n+1, vector<int>(3, 0));
	vector< vector<int> > pay(n+1, vector<int>(3, 0));

	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			// i��° ���� ���� �ʷ� �Ķ����� ĥ�ϴ� ������ ���
			cin >> house[i][j];
		}
	}
	house[0][0] = house[0][1] = house[0][2] = 0;
	pay[0][0] = pay[0][1] = pay[0][2] = 0;

	cout << " ====================" << endl;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			cout << house[i][j] << " ";
		}
		cout << endl;
	}


	for (i = 1; i <= n; i++) {
		// pay[i][j]�� ����� ���ؼ� pay[i-1][j::] , house[i][j] �� 
		for (j = 0; j < 3; j++) {
			int minn = 2147000000;
			for (k = 0; k < 3; k++) {
				if (k == j) continue;
				else if (pay[i - 1][k] < minn) minn = pay[i - 1][k];
			}
			pay[i][j] = house[i][j] + minn;
			cout << i << "," << j << " : " << pay[i][j] << endl;
		}
	}


	cout << "=====================" << endl;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			cout << pay[i][j] << " ";
		}
		cout << endl;
	}


	cout << *min_element(pay[n].begin(), pay[n].end()) << endl;
	for (auto i : pay[n]) {
		cout << i << endl;
	}

	return 0;
}