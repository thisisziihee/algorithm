/*
N개의 원소로 구성된 자연수 집합이 주어지면, 이 집합을 두 개의 부분집합으로 나누었을 때
두 부분집합의 원소의 합이 서로 같은 경우가 존재하면 “YES"를 출력하고, 그렇지 않으면 ”NO"를 출력하는 프로그램을 작성하세요.
예를 들어 {1, 3, 5, 6, 7, 10}이 입력되면 {1, 3, 5, 7} = {6, 10} 으로 두 부분집합의 합이 16으로 같은 경우가 존재하는 것을 알 수 있다.
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int num, totalSum = 0;
int value[11];
bool flag = false;

void dfs(int index, int sum) {
	if (sum > (totalSum / 2)) return;
	if (flag == true) return;
	if (index == num + 1) {
		if (sum == totalSum - sum) {
			flag = true;
		}
	}
	else {
		dfs(index + 1, sum + value[index]);
		dfs(index + 1, sum);
	}
}

int main() {
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &value[i]);
		totalSum += value[i];
	}
	dfs(1, 0);
	if (flag == true) printf("YES");
	else printf("NO");
	return 0;
}