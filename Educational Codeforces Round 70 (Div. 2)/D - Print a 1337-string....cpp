#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int tmp = 0;
		int ans, x = 0;
		for (int i = 2; i <= 100001; i++) {
			tmp = i * (i - 1) / 2;
			if (tmp == n) {
				ans = i;
				break;
			}
			else if (tmp > n) {
				ans = i - 1;
				x = n - (i - 1) * (i - 2) / 2;
				break;
			}
		}
		if (x) {
			printf("133");
			while (x--) printf("7");
			ans -= 2;
		}
		else printf("1");
		while (ans--) printf("3");
		printf("7\n");
	}

	return 0;
}