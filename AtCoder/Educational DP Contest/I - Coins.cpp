#include <cstdio>
using namespace std;

/* 🐣🐥 */
double p[3000], ans;
double dp[3000][3001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &p[i]);
	}
	dp[0][0] = 1 - p[0], dp[0][1] = p[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] * (1 - p[i]);
		for (int j = 1; j <= i + 1; j++) {
			dp[i][j] += dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]);
		}
	}
	for (int i = n / 2 + 1; i <= n; i++) {
		ans += dp[n - 1][i];
	}
	printf("%.10lf", ans);

	return 0;
}