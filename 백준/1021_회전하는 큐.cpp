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
	// m개의 값을 모두 뽑아낸 경우, 최소 이동 횟수 갱신
	if (m_idx == m) {
		if (ans == -1 || ans > cnt) ans = cnt;
		return;
	}

	// 1. 현재 뽑아야 하는 값 m_arr[m_idx]이 temp 배열에서 어떤 위치에 있나 확인
	int i;
	for (i = 0; i < temp.size(); i++) {
		if (temp[i] == m_arr[m_idx]) break;
	}

	// 0번 인덱스에서 i번째 인덱스까지 왼쪽 이동이 빠른지 오른쪽 이동이 빠른지 확인
	int left_move = i;
	int right_move = temp.size() - i;

	int cnt_temp = 0;

	// 왼쪽으로 이동
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


	// 오른쪽으로 이동
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