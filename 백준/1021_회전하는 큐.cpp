#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
vector<int> m_arr;
vector<int> anss;

int ans = -1;

void solution(int m_idx, int cnt, vector<int> temp) {
	// m���� ���� ��� �̾Ƴ� ���, �ּ� �̵� Ƚ�� ����
	if (m_idx == m) {
		if (ans == -1 || ans > cnt) ans = cnt;
		return;
	}

	// 1. ���� �̾ƾ� �ϴ� �� m_arr[m_idx]�� temp �迭���� � ��ġ�� �ֳ� Ȯ��
	int i;
	for (i = 0; i < temp.size(); i++) {
		if (temp[i] == m_arr[m_idx]) break;
	}

	// 0�� �ε������� i��° �ε������� ���� �̵��� ������ ������ �̵��� ������ Ȯ��
	int left_move = i;
	int right_move = temp.size() - i;

	int cnt_temp = 0;

	// �������� �̵�
	if (left_move < right_move) {
		for (int i = 0; i < temp.size(); i++) {
			if (temp[0] == m_arr[m_idx]) {
				temp.erase(temp.begin());
				solution(m_idx + 1, cnt + cnt_temp, temp);
				break;
			}
			temp.push_back(temp[0]);
			temp.erase(temp.begin());
			cnt_temp += 1;
		}
	}


	// ���������� �̵�
	else {
		for (int i = 0; i < temp.size(); i++) {
			if (temp[0] == m_arr[m_idx]) {
				temp.erase(temp.begin());
				solution(m_idx + 1, cnt + cnt_temp, temp);
				break;
			}
			temp.insert(temp.begin(), temp.back());
			temp.erase(temp.end() - 1);
			cnt_temp += 1;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) arr.push_back(i);

	m_arr = vector<int>(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> m_arr[i];
	}

	solution(0, 0, arr);
	cout << ans << endl;
}