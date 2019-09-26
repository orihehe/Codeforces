#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[300001];
ll dp[11][300001];
int main() {
	int n, m, k;
	ll ans = 0;
	scanf("%d %d %d", &n, &m, &k);
	memset(dp, -0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		dp[1][i] = max(dp[m][i - 1] + arr[i], (ll)arr[i]) - k;
		ans = max(dp[1][i], ans);
		for (int j = 2; j <= m; j++) {
			dp[j][i] = max(dp[j - 1][i - 1] + arr[i], (ll)arr[i] - k);
			ans = max(dp[j][i], ans);
		}
	}
	printf("%lld", ans);

	return 0;
}