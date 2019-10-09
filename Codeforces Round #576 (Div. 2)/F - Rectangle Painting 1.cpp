#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char arr[52][52];
int dp[52][52][52][52], hap[52][52];
int dfs(int l, int r, int s, int e) {
	if (hap[r][e] - hap[r][s - 1] - hap[l - 1][e] + hap[l - 1][s - 1] == 0) return 0;
	if (dp[l][r][s][e] != -1) return dp[l][r][s][e];
	int ret = 100;
	if (l < r) {
		for (int i = l; i < r; i++) {
			ret = min(ret, dfs(l, i, s, e) + dfs(i + 1, r, s, e));
		}
	}
	if (s < e) {
		for (int i = s; i < e; i++) {
			ret = min(ret, dfs(l, r, s, i) + dfs(l, r, i+1, e));
		}
	}
	ret = min(ret, max(r - l + 1, e - s + 1));
	return dp[l][r][s][e] = ret;
}
int main() {
	int n;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		scanf("%s", arr[i] + 1);
		for (int j = 1; j <= n; j++) {
			hap[i][j] += hap[i - 1][j] + hap[i][j - 1] - hap[i-1][j-1] + (arr[i][j] == '#');
		}
	}
	printf("%d", dfs(1, n, 1, n));

	return 0;
}