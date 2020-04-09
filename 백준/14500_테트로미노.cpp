/*
�������̳�� ũ�Ⱑ 1��1�� ���簢���� ���� �� �̾ ���� �����̸�, ������ ���� ������ �����ؾ� �Ѵ�.
- ���簢���� ���� ��ġ�� �� �ȴ�.
- ������ ��� ����Ǿ� �־�� �Ѵ�.
- ���簢���� ������ ����Ǿ� �־�� �Ѵ�. ��, �������� �������� �´�� ������ �� �ȴ�.
- ���簢�� 4���� �̾� ���� �������̳�� ��Ʈ�ι̳��� �ϸ�, ������ ���� 5������ �ִ�.


�Ƹ��̴� ũ�Ⱑ N��M�� ���� ���� ��Ʈ�ι̳� �ϳ��� �������� �Ѵ�. ���̴� 1��1 ũ���� ĭ���� �������� ������, ������ ĭ���� ������ �ϳ� ���� �ִ�.
��Ʈ�ι̳� �ϳ��� ������ ���Ƽ� ��Ʈ�ι̳밡 ���� ĭ�� ���� �ִ� ������ ���� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.
��Ʈ�ι̳�� �ݵ�� �� ���簢���� ��Ȯ�� �ϳ��� ĭ�� �����ϵ��� ���ƾ� �ϸ�, ȸ���̳� ��Ī�� ���ѵ� �ȴ�.

�Է�
ù° �ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. (4 �� N, M �� 500)
��° �ٺ��� N���� �ٿ� ���̿� ���� �ִ� ���� �־�����. 
i��° ���� j��° ���� ���������� i��° ĭ, ���ʿ������� j��° ĭ�� ���� �ִ� ���̴�. �Է����� �־����� ���� 1,000�� ���� �ʴ� �ڿ����̴�.

���
ù° �ٿ� ��Ʈ�ι̳밡 ���� ĭ�� ���� ������ ���� �ִ��� ����Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector< vector<int> > arr;
vector< vector<int> > check;
int ans = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void solution(int y, int x, int sum, int cnt) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}
	else {
		int xx, yy;
		for (int k = 0; k < 4; k++) {
			xx = x + dx[k];
			yy = y + dy[k];
			if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
				if (check[yy][xx] == 0) {
					check[yy][xx] = 1;
					solution(yy, xx, sum + arr[yy][xx], cnt + 1);
					check[yy][xx] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	arr = vector< vector<int> > (n, vector<int>(m, 0));
	check = vector< vector<int> >(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j + 2 < m) {
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
				if (i + 1 < n) ans = max(ans, temp + arr[i + 1][j+1]);
				if (i - 1 < n && i - 1 >= 0) ans = max(ans, temp + arr[i - 1][j+1]);
			}
			if (i + 2 < n) {
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
				if (j + 1 < m) ans = max(ans, temp + arr[i + 1][j + 1]);
				if (j - 1 < m && j - 1 >= 0) ans = max(ans, temp + arr[i + 1][j - 1]);
			}
			check[i][j] = 1;
			solution(i, j, arr[i][j], 1);
			check[i][j] = 0;
		}
	}
	
	cout << ans << endl;
}