#include <cstdio>
#include <cstring>
#define ll long long
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
ll dp[100001][2][2], dd[100001];
int n, m;
ll dfs(int cur, int w, int num) {
	if (m - 1 == cur) return 1;
	if (dp[cur][w][num] != -1) return dp[cur][w][num];
	ll ret = dfs(cur + 1, !w, 0);
	if (num == 0) {
		ret += dfs(cur + 1, w, 1);
	}
	return dp[cur][w][num] = ret % mod;
}
ll go(int cur) {
	if (n == cur) return 1;
	if (cur >= n) return 0;
	if (dd[cur] != -1) return dd[cur];
	ll ret = go(cur + 1) + go(cur + 2);
	return dd[cur] = ret % mod;
}
int main() {
	memset(dp, -1, sizeof(dp));
	memset(dd, -1, sizeof(dd));
	scanf("%d %d", &n, &m);
	printf("%lld", (dfs(0, 0, 0) * 2 + (n > 1 ? go(0) * 2 - 2 : 0) + mod) % mod);

	return 0;
}