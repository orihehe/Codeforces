/*
SWEA 3752. 가능한 시험점수

동전문제와 비슷하게 풀면 된다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int main() {
	int t, n, x, cnt = 0;
	bool s[10001];
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &x);
		memset(s, false, sizeof(s));
		s[0] = true;
		cnt = 0;
		while (x--) {
			scanf("%d", &n);
			for (int j = 10000 - n; j >= 0; j--) {
				if (s[j]) s[j + n] = true;
			}
		}
		for (int j = 0; j <= 10000; j++) if (s[j]) cnt++;
		printf("#%d %d\n", i, cnt);
	}

	return 0;
}