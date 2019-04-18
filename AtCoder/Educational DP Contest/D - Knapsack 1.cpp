/*
무게를 기준으로 냅색, 같은 무게라면 큰 값을 저장
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll dp[100001], b, ans;
int main() {
	int n, w, a;
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &w);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %lld", &a, &b);
		for (int j = w; j >= a; j--) {
			if (dp[j - a] != -1) {
				dp[j] = max(dp[j], dp[j - a] + b);
			}
		}
	}
	for (int i = w; i >= 0; i--) if (dp[i] != -1) ans = max(ans, dp[i]);
	printf("%lld", ans);

	return 0;
}