#include<bits/stdc++.h>
using namespace std;

int n, m, h;
int arr[100][100];

// i��° ��ٸ� Ÿ�⸦ �����ؼ� ������ ����� ��ȯ
int draw_straws(int i) {
	int now = 1;
	while (now <= h) {
		if (arr[now][i] == 1) i += 1;
		else if (arr[now][i] == 2) i -= 1;
		now += 1;
	}
	return i;
}


// ���� arr���� ��ٸ�Ÿ�⸦ �����ϸ� ���μ� i�� i�� �����ϴ��� Ȯ��
bool check_i_to_i() {
	for (int i = 1; i <= n; i++) {
		int temp = draw_straws(i);
		if (temp != i) return false;
	}
	return true;
}


int main() {
	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		// (a,b)���� 1, (a, b+1)���� 2�� �����ؼ� ���� �̾��� ���μ����� ��Ÿ��
		// Ư�� ��ġ�� �������� ��, ��ǥ���� 1�̸� ���������� �̵�, 2�̸� �������� �̵�
		arr[a][b] = 1;
		arr[a][b + 1] = 2;
	}

	// ���μ��� �� �� �ִ� �ĺ� ��� ����
	vector< pair<int, int> > aa;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n - 1; j++) {
			if (arr[i][j] == 0 && arr[i][j + 1] == 0) {
				aa.emplace_back(i, j);
			}
		}
	}

	// �̹� ������ ������ �����ϴ� ���
	if (check_i_to_i()) {
		cout << 0 << endl;
		return 0;
	}

	int ans = -1;

	for (int i = 0; i < aa.size(); i++) {
		int a1 = aa[i].first;
		int b1 = aa[i].second;
		if (arr[a1][b1] != 0 || arr[a1][b1 + 1] != 0) continue;
		arr[a1][b1] = 1;
		arr[a1][b1 + 1] = 2;
		if (check_i_to_i()) {
			// �ּ� ���μ����� �����ϴ� ��찡 ���� �� �����Ƿ� �ٷ� ������ �ȵ�
			if (ans == -1 || ans > 1)
				ans = 1;
		}
		for (int j = i + 1; j < aa.size(); j++) {
			int a2 = aa[j].first;
			int b2 = aa[j].second;
			if (arr[a2][b2] != 0 || arr[a2][b2 + 1] != 0) continue;
			arr[a2][b2] = 1;
			arr[a2][b2 + 1] = 2;
			if (check_i_to_i()) {
				if (ans == -1 || ans > 2) {
					ans = 2;
				}
			}
			for (int k = j + 1; k < aa.size(); k++) {
				int a3 = aa[k].first;
				int b3 = aa[k].second;
				if (arr[a3][b3] != 0 || arr[a3][b3 + 1] != 0) continue;
				arr[a3][b3] = 1;
				arr[a3][b3 + 1] = 2;
				if (check_i_to_i()) {
					if (ans == -1 || ans > 3) {
						ans = 3;
					}
				}
				arr[a3][b3] = 0;
				arr[a3][b3 + 1] = 0;
			}
			arr[a2][b2] = 0;
			arr[a2][b2 + 1] = 0;
		}
		arr[a1][b1] = 0;
		arr[a1][b1 + 1] = 0;
	}
	cout << ans << endl;

	return 0;
}