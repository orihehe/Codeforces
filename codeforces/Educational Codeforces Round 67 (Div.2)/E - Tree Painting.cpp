#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
vector<int> vec[200001];
ll dp[2][200001], ch[200001], ans;
int n;
void dfs(int cur, int p) {
	ch[cur]++;
	for (int v : vec[cur]) {
		if (v != p) {
			dfs(v, cur);
		}
	}
	ll tmp = 0, mx = 0;
	int idx = -1;
	for (int v : vec[cur]) {
		if (v != p) {
			if (mx < dp[1][v] - dp[0][v] - ch[v]) {
				mx = dp[1][v] - dp[0][v] - ch[v];
				idx = v;
			}
			ch[cur] += ch[v];
			tmp += dp[0][v];
		}
	}
	dp[0][cur] = ch[cur] + tmp;
	dp[1][cur] = tmp + n + mx;
	ans = max({ ans, dp[0][cur],dp[1][cur] });
}
int main() {
	int a, b;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 1);
	printf("%lld", ans);

	return 0;
}