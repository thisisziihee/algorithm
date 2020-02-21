/*
지니레코드에서는 불세출의 가수 조영필의 라이브 동영상을 DVD로 만들어 판매하려 한다. DVD에는 총 N개의 곡이 들어가는데, DVD에 녹화할 때에는 라이브에서의 순서가 그대로 유지되어야 한다.
순서가 바뀌는 것을 우리의 가수 조영필씨가 매우 싫어한다. 즉, 1번 노래와 5번 노래를 같은 DVD에 녹화하기 위해서는 1번과 5번 사이의 모든 노래도 같은 DVD에 녹화해야한다.
또한 한 노래를 쪼개서 두 개의 DVD에 녹화하면 안된다. 지니레코드 입장에서는 이 DVD가 팔릴 것인지 확신할 수 없기 때문에 이 사업에 낭비되는 DVD를 가급적 줄이려고 한다.
고민 끝에 지니레코드는 M개의 DVD에 모든 동영상을 녹화하기로 하였다. 이 때 DVD의 크기(녹화 가능한 길이)를 최소로 하려고 한다.
그리고 M개의 DVD는 모두 같은 크기여야 제조원가가 적게 들기 때문에 꼭 같은 크기로 해야 한다.
▣ 입력설명
첫째 줄에 자연수 N(1≤N≤1,000), M(1≤M≤N)이 주어진다. 다음 줄에는 조영필이 라이브에서 부른 순서대로 부른 곡의 길이가 분 단위로(자연수) 주어진다.
부른 곡의 길이는 10,000분을 넘지 않는다고 가정하자.
▣ 출력설명 : 첫 번째 줄부터 DVD의 최소 용량 크기를 출력하세요.
*/

#include<stdio.h>
int n, song[1001];

// DVD 한 개의 용량이 주어졌을 때, 넣을 수 있는 곡의 개수
int Count(int size) {
	int i, cnt = 1, sum = 0;
	for (i = 0; i < n; i++) {
		if (sum + song[i] > size) {
			cnt++;
			sum = song[i];
		}
		else sum += song[i];
	}
	return cnt;
}

int main() {
	int  m, i, left = 0, right = 0, mid, res=0, maxx = -2147000000;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		scanf("%d", &song[i]);
		// 어차피 right의 값은 가장 큰 값으로 해야하므로 곡의 총 길이로 한다.
		right += song[i];
		maxx = (song[i] > maxx ? song[i] : maxx);
	}

	while (left <= right) {
		// dvd 한 개의 최소 용량이 됨
		mid = (left + right) / 2;
		if (mid >= maxx && Count(mid) > m) {
			left = mid + 1;
		}
		else {
			res = mid;
			right = mid - 1;
		}
	}
	printf("%d", res);
}