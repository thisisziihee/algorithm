#include<bits/stdc++.h>
using namespace std;

int N, L;

bool isitOK(vector<int> &load) {
	vector<bool> visited(N, false);

	for (int i = 1; i < N; i++) {
		if (load[i] != load[i - 1]) {
			int diff = load[i] - load[i - 1];

			// �� ĭ�� ���� ���̰� 1�� �Ѵ� ���
			if (abs(diff) != 1) return false;

			if (load[i] > load[i - 1]) {
				for (int j = 1; j <= L; j++) {
					
					// L���� ���ӵ��� ���� ���
					if (i - j < 0) return false;

					// L���� ĭ���� ���̰� ���� �ٸ� ���
					if (load[i - 1] != load[i - j]) return false;

					// �̹� ���ΰ� ������ ���
					if (visited[i - j]) return false;

					// ���� ���� ������ ��� �����Ѵٸ� ���� ��ġ
					visited[i - j] = true;
				}
			}

			else {
				for (int j = 0; j < L; j++) {
					// L���� ���ӵ��� �ʴ� ���
					if (i + j >= N) return false;

					// L���� ĭ���� ���̰� ���� �ٸ� ���
					if (load[i] != load[i + j]) return false;

					// �̹� ���ΰ� ��ġ�Ǿ��ִ� ���
					if (visited[i + j]) return false;

					// ��� ������ �����Ѵٸ� ���� ��ġ
					visited[i + j] = true;
				}
			}
		}
	}
	return true;
}

int main() {
	cin >> N >> L;
	
	vector< vector<int> > arr(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;

	// �� �˻�
	for (int i = 0; i < N; i++) {
		vector<int> d;
		for (int j = 0; j < N; j++) {
			d.push_back(arr[i][j]);
		}
		if (isitOK(d)) ans += 1;
	}

	// �� �˻�
	for (int i = 0; i < N; i++) {
		vector<int> d;
		for (int j = 0; j < N; j++) {
			d.push_back(arr[j][i]);
		}
		if (isitOK(d)) ans += 1;
	}

	cout << ans << endl;
}