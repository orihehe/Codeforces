#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int dp[3002][3002], cp;
char ans[3002];
int main() {
	char a[3002], b[3002];
	int al, bl, ap, bp;
	scanf("%s %s", a + 1, b + 1);
	al = strlen(a + 1), bl = strlen(b + 1);
	for (int i = 1; i <= al; i++) {
		for (int j = 1; j <= bl; j++) {
			dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (a[i] == b[j]) });
		}
	}
	ap = al, bp = bl;
	while (ap >= 1 && bp >= 1) {
		if (dp[ap - 1][bp] == dp[ap][bp]) ap--;
		else if (dp[ap][bp - 1] == dp[ap][bp]) bp--;
		else {
			ans[cp++] = a[ap];
			ap--, bp--;
		}
	}

	for (int i = cp - 1; i >= 0; i--) printf("%c", ans[i]);

	return 0;
}