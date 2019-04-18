#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAX 2000000001
using namespace std;

/* 🐣🐥 */
int h[100001];
int dp[100001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	fill(dp, dp + n, MAX);
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int k = 1; i - k >= 0 && k <= m; k++) {
			dp[i] = min(dp[i], dp[i - k] + abs(h[i - k] - h[i]));
		}
	}
	printf("%d", dp[n - 1]);

	return 0;
}