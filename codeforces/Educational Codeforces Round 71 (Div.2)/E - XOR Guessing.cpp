#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int x, res, ans = 0;
	printf("? "); x = 127;
	for (int i = 0; i < 100; i++) {
		printf("%d ", x);
		x += 128;
	}
	printf("\n");
	fflush(stdout);
	scanf("%d", &res);
	for (int i = 0; i < 7; i++) {
		if ((res | (1 << i)) > res) ans += (1 << i);
	}
	printf("? "); x = 16256;
	for (int i = 0; i < 100; i++) {
		printf("%d ", x++);
	}
	printf("\n");
	fflush(stdout);
	scanf("%d", &res);
	for (int i = 7; i < 14; i++) {
		if ((res | (1 << i)) > res) ans += (1 << i);
	}
	printf("! %d\n", ans);
	fflush(stdout);

	return 0;
}