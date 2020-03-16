/*
�ְ� 17kg�� ���Ը� ������ �� �ִ� ������ �ִ�. �׸��� ���� 3kg, 4kg, 7kg, 8kg, 9kg�� ���Ը� ���� 5������ ������ �ִ�. 
�� �������� ��ġ�� ���� 4, 5, 10, 11, 13�̴�. �� ������ ���濡 ��µ� 17kg�� ���� �����鼭 �ִ��� ��ġ�� �ǵ��� �Ϸ��� ��� ��ƾ� �ұ��? 
�� ������ ������ ������ ������ ����. �� ������ ������ ���� �� ���濡 ���� �� �ִٴ� ���Դϴ�.

�� �Է¼���
ù ��° ���� ���� ������ ������ ���濡 ���� �� �ִ� ������ �Ѱ谪�� �־�����.
�� ��° �ٺ��� �� ������ ���Կ� ��ġ�� �־�����.
������ ���幫�Դ� 1000kg�� ���� �ʴ´�. ������ ������ 30�� �̳��̴�.

�� ��¼��� : ù ��° �ٿ� ���濡 ���� �� �ִ� ������ �ִ밡ġ�� ����Ѵ�

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
	//value_per_weight[i] : i ���Կ��� ���� �� �ִ� �ִ� ��ġ��

	for (int i = 0; i < jewel_cnt; i++) {
		cin >> jewel_weight >> jewel_value;
		for (int j = jewel_weight; j <= limit_weight; j++) {

			// j ���Ը� �����ʴ� ������ ���� �߿��� ���� �ִ� ��ġ��
			// j - jewel_weight + jewel_weight = j �̹Ƿ�, j - jewel_weight �� �ǹ̴� ���� jewel_weight��ŭ �߰��ϱ����ؼ� ���� Ȯ��
			int temp = value_per_weight[j - jewel_weight] + jewel_value;

			// ���������� ���� ������ ���� �� ��ġ�� ũ��, j���� ���� ���� �� �ִ� �� ����
			if (value_per_weight[j] < temp) value_per_weight[j] = temp;
		}
	}
	cout << value_per_weight[limit_weight] << endl;
}