/*
▣ 입력설명 : 첫째 줄에는 선수의 수를 의미하는 정수 N이 주어진다. N은 3 이상 10,000 이하이다. 다음줄에는 N개의 정수가 주어진다. 
	이 값들은 각 선수들의 평소 실력을 앞에서 달리고 있는 선수부터 제시한 것이다. 각 정수는 1 이상 100,000 이하이다. 
	참가한 선수의 평소실력은 같을 수 있습니다. 그리고 실력이 같다면 앞에 달리는 선수를 앞지를 수 없습니다.
▣ 출력설명 : 각 선수의 최선의 등수를 나타내는 정수 N개를 입력에 주어진 선수 순서와 동일한 순서로 한줄에 출력한다.	모든 정수들 사이에는 하나의 공백을 둔다.
*/

#include<stdio.h>
#include<vector>
int main() {
	int n, i, j, rank = 0;
	scanf("%d", &n);
	std::vector<int> player(n);

	for (i = 0; i < n; i++) {
		scanf("%d", &player[i]);
	}
	printf("1 ");
	for (i = 1; i < n; i++) {
		rank = 1;
		for (j = i-1; j >= 0; j--) {
			if (player[j] >= player[i]) rank++;
		}
		printf("%d ", rank);
	}
}