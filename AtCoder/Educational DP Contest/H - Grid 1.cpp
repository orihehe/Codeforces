#include <cstdio>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
char b[1001][1001];
int dp[1001][1001];
int main() {
	int n, m, ap = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	while (ap < n) {
		if (b[ap][0] == '#') break;
		dp[ap++][0] = 1;
	}
	ap = 0;
	while (ap < m) {
		if (b[0][ap] == '#') break;
		dp[0][ap++] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (b[i][j] == '#') continue;
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	printf("%d", dp[n - 1][m - 1]);

	return 0;
}