#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int yy, xx, val;
int arr[101][101];
int numCnt[101];


int solution() {
	int hang = 3;	// 행 : 배열의 가로줄의 개수. y 길이
	int yeol = 3;	// 열 : 배열의 세로줄의 개수. x 길이
	int ans = 0;

	while (true) {
		if (arr[yy][xx] == val) break;
		if (ans > 100) { ans = -1; break; }

		// 정사각형이거나 세로의 길이가 더 긴 형태
		// 행에 대해서 정렬
		if (hang >= yeol) {

			vector<int> size;

			for (int i = 1; i <= hang; i++) {

				// i행에서 (수, 등장횟수) 저장
				// pair는 first 값 오름차순 -> second 값 오름차순으로 정렬되므로, first에는 등장 횟수, second에는 수 저장
				// 그리고 다시 arr배열에 담을 때에는 반대로 저장
				vector< pair<int, int> > temp;
				
				// 수에 대한 등장 횟수를 저장할 배열
				memset(numCnt, 0, sizeof(numCnt));

				// 1. i배열에 있는 값과 등장 횟수 체크
				for (int j = 1; j <= yeol; j++) numCnt[arr[i][j]] += 1;
				
				// 2. 유효한 값을 (등장 횟수, 수) 형태로 temp 벡터에 저장
				for (int j = 1; j <= 100; j++) {
					if (numCnt[j] == 0) continue;
					temp.push_back(make_pair(numCnt[j], j));
				}

				// 3. 등장횟수 오름차순 -> 수 오름차순으로 정렬
				sort(temp.begin(), temp.end());

				// 4. arr 배열에 저장하기 위해 기존 값 0으로 초기화 (길이가 달라질 수 있으므로 그냥 0 초기화)
				for (int j = 1; j <= yeol; j++) arr[i][j] = 0;

				// 5. temp벡터의 second, first 값을 arr로 복사
				int idx = 1;
				for (int j = 0; j < temp.size(); j++) {
					arr[i][idx++] = temp[j].second; 
					arr[i][idx++] = temp[j].first;
				}
				idx -= 1;

				// i행의 연산을 마친 이후에 i행의 길이 push_back
				size.push_back(idx);
			}
			// 각 행의 길이를 담은 size 배열에서 가장 큰 크기는 다음 턴에서 열 값이 된다.
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
