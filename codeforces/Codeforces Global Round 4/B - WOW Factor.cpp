#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
char st[1000002];
ll dp[2][1000010];
int main() {
	ll ans = 0;
	scanf("%s", st + 1);
	int len = strlen(st + 1);
	for (int i = 1; i <= len; i++) {
		if (st[i] == 'o') {
			dp[1][i] = dp[0][i - 1];
		}
		else if (st[i + 1] == 'v') {
			ans += dp[1][i - 1];
			dp[0][i]++;
		}
		dp[0][i] += dp[0][i - 1];
		dp[1][i] += dp[1][i - 1];
	}
	printf("%lld", ans);

	return 0;
}
