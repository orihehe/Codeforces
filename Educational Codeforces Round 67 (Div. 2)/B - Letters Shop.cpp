#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[200001], f[200001];
int dp[26][200001], num[26];
int main() {
	int n, k;
	scanf("%d %s", &n, st);
	dp[st[0] - 'a'][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			dp[j][i] = dp[j][i - 1] + (st[i] - 'a' == j);
		}
	}
	scanf("%d", &k);
	int ans = 0;
	while (k--) {
		ans = 0;
		scanf("%s", f);
		int len = strlen(f);
		memset(num, 0, sizeof(num));
		for (int j = 0; j < len; j++) {
			num[f[j] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			int idx = lower_bound(dp[i], dp[i] + n, num[i]) - dp[i];
			ans = max(ans, idx);
		}
		printf("%d\n", ans + 1);
	}

	return 0;
}