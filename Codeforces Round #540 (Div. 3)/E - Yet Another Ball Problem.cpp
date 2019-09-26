/*
짝을 만들 수 있는 가짓수는 k*(k-1)
앞 수는 k=4 라면 1,2,3,4,1,2,3,4,1,... 순으로
뒷 수는 2,3,4,1/3,4,1,2/4,1,2,3 순으로 배치해주면 조건을 모두 만족한다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int main() {
	int n, k, fr = 1, se, last = 1;
	scanf("%d %d", &n, &k);
	if ((ll)k*((ll)k - 1) < (ll)n) return !printf("nO");
	printf("yEs\n");
	for (int i = 0; i < n; i++) {
		if (fr == 1) {
			se = ++last;
		}
		if (se == k + 1)se = 1;
		if (fr == k + 1) fr = 1;
		printf("%d %d\n", fr, se);
		fr++, se++;
		if (se == k + 1)se = 1;
		if (fr == k + 1) fr = 1;
	}

	return 0;
}