#include<stdio.h>
#include<algorithm>

int main() {
		// �빮�� (65 ~ 90)���� -64. �ҹ��� (97 ~ 122)���� -70�� �Ͽ� ���ĺ� 52���� int �迭 ����
	int str1Cnt[60] = { 0 };
	int str2Cnt[60] = { 0 };

	char str[100];
	scanf("%s", &str);

		// ������ �ƽ�Ű�ڵ忡 �ش��ϴ� �ε����� ī����
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90) str1Cnt[str[i] - 64]++;
		else str1Cnt[str[i] - 70]++;
	}

	scanf("%s", &str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90) str2Cnt[str[i] - 64]++;
		else if (str[i] >= 97 && str[i] <= 122) str2Cnt[str[i] - 70]++;
	}

		// �� �迭�� ������ ���ؼ� ������ ��ġ�ϸ� �Ƴ��׷� �Ǻ�
	for (int i = 1; i <= 52; i++) {
		if (str1Cnt[i] != str2Cnt[i]) {
			printf("NO\n");
			exit(0);
		}
	}
	printf("YES\n");
	return 0;
}