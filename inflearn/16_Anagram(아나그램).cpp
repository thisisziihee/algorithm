#include<stdio.h>
#include<algorithm>

int main() {
		// 대문자 (65 ~ 90)에는 -64. 소문자 (97 ~ 122)에는 -70을 하여 알파벳 52개의 int 배열 생성
	int str1Cnt[60] = { 0 };
	int str2Cnt[60] = { 0 };

	char str[100];
	scanf("%s", &str);

		// 문자의 아스키코드에 해당하는 인덱스에 카운팅
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90) str1Cnt[str[i] - 64]++;
		else str1Cnt[str[i] - 70]++;
	}

	scanf("%s", &str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90) str2Cnt[str[i] - 64]++;
		else if (str[i] >= 97 && str[i] <= 122) str2Cnt[str[i] - 70]++;
	}

		// 두 배열을 끝까지 비교해서 완전히 일치하면 아나그램 판별
	for (int i = 1; i <= 52; i++) {
		if (str1Cnt[i] != str2Cnt[i]) {
			printf("NO\n");
			exit(0);
		}
	}
	printf("YES\n");
	return 0;
}