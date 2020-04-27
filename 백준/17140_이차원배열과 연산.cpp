#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int yy, xx, val;
int arr[101][101];
int numCnt[101];


int solution() {
	int hang = 3;	// �� : �迭�� �������� ����. y ����
	int yeol = 3;	// �� : �迭�� �������� ����. x ����
	int ans = 0;

	while (true) {
		if (arr[yy][xx] == val) break;
		if (ans > 100) { ans = -1; break; }

		// ���簢���̰ų� ������ ���̰� �� �� ����
		// �࿡ ���ؼ� ����
		if (hang >= yeol) {

			vector<int> size;

			for (int i = 1; i <= hang; i++) {

				// i�࿡�� (��, ����Ƚ��) ����
				// pair�� first �� �������� -> second �� ������������ ���ĵǹǷ�, first���� ���� Ƚ��, second���� �� ����
				// �׸��� �ٽ� arr�迭�� ���� ������ �ݴ�� ����
				vector< pair<int, int> > temp;
				
				// ���� ���� ���� Ƚ���� ������ �迭
				memset(numCnt, 0, sizeof(numCnt));

				// 1. i�迭�� �ִ� ���� ���� Ƚ�� üũ
				for (int j = 1; j <= yeol; j++) numCnt[arr[i][j]] += 1;
				
				// 2. ��ȿ�� ���� (���� Ƚ��, ��) ���·� temp ���Ϳ� ����
				for (int j = 1; j <= 100; j++) {
					if (numCnt[j] == 0) continue;
					temp.push_back(make_pair(numCnt[j], j));
				}

				// 3. ����Ƚ�� �������� -> �� ������������ ����
				sort(temp.begin(), temp.end());

				// 4. arr �迭�� �����ϱ� ���� ���� �� 0���� �ʱ�ȭ (���̰� �޶��� �� �����Ƿ� �׳� 0 �ʱ�ȭ)
				for (int j = 1; j <= yeol; j++) arr[i][j] = 0;

				// 5. temp������ second, first ���� arr�� ����
				int idx = 1;
				for (int j = 0; j < temp.size(); j++) {
					arr[i][idx++] = temp[j].second; 
					arr[i][idx++] = temp[j].first;
				}
				idx -= 1;

				// i���� ������ ��ģ ���Ŀ� i���� ���� push_back
				size.push_back(idx);
			}
			// �� ���� ���̸� ���� size �迭���� ���� ū ũ��� ���� �Ͽ��� �� ���� �ȴ�.
			sort(size.begin(), size.end());
			yeol = size.back();
		}

		else {
			vector<int> size;
			for (int j = 1; j <= yeol; j++) {
				vector< pair<int, int> > temp;
				memset(numCnt, 0, sizeof(numCnt));

				for (int i = 1; i <= hang; i++) numCnt[arr[i][j]] += 1;

				for (int i = 1; i <= 100; i++) {
					if (numCnt[i] == 0) continue;
					temp.push_back(make_pair(numCnt[i], i));
				}
				sort(temp.begin(), temp.end());

				for (int i = 1; i <= hang; i++) arr[i][j] = 0;

				int idx = 1;
				for (int i = 0; i < temp.size(); i++) {
					arr[idx++][j] = temp[i].second;
					arr[idx++][j] = temp[i].first;
				}
				idx -= 1;
				size.push_back(idx);
			}
			sort(size.begin(), size.end());
			hang = size.back();
		}

		ans += 1;
	}
	return ans;
}


int main() {
	cin >> yy >> xx >> val;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	cout << solution() << endl;
}
