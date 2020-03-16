/*
최고 17kg의 무게를 저장할 수 있는 가방이 있다. 그리고 각각 3kg, 4kg, 7kg, 8kg, 9kg의 무게를 가진 5종류의 보석이 있다. 
이 보석들의 가치는 각각 4, 5, 10, 11, 13이다. 이 보석을 가방에 담는데 17kg를 넘지 않으면서 최대의 가치가 되도록 하려면 어떻게 담아야 할까요? 
각 종류별 보석의 개수는 무한이 많다. 한 종류의 보석을 여러 번 가방에 담을 수 있다는 뜻입니다.

▣ 입력설명
첫 번째 줄은 보석 종류의 개수와 가방에 담을 수 있는 무게의 한계값이 주어진다.
두 번째 줄부터 각 보석의 무게와 가치가 주어진다.
가방의 저장무게는 1000kg을 넘지 않는다. 보석의 개수는 30개 이내이다.

▣ 출력설명 : 첫 번째 줄에 가방에 담을 수 있는 보석의 최대가치를 출력한다

4 11
5 12
3 8
6 14
4 8
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	vector< pair<int, int> > jewels;

	int jewel_cnt, limit_weight;
	int jewel_weight, jewel_value;

	cin >> jewel_cnt >> limit_weight;

	vector<int> value_per_weight(limit_weight + 1, 0);
	//value_per_weight[i] : i 무게에서 얻을 수 있는 최대 가치값

	for (int i = 0; i < jewel_cnt; i++) {
		cin >> jewel_weight >> jewel_value;
		for (int j = jewel_weight; j <= limit_weight; j++) {

			// j 무게를 넘지않는 보석의 조합 중에서 가장 최대 가치값
			// j - jewel_weight + jewel_weight = j 이므로, j - jewel_weight 의 의미는 새로 jewel_weight만큼 추가하기위해서 공간 확보
			int temp = value_per_weight[j - jewel_weight] + jewel_value;

			// 기존값보다 새로 적용한 값이 더 가치가 크면, j무게 에서 얻을 수 있는 값 갱신
			if (value_per_weight[j] < temp) value_per_weight[j] = temp;
		}
	}
	cout << value_per_weight[limit_weight] << endl;
}