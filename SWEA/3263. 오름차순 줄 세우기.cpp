#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[100001];
int main()
{
	int n, maxC, t, x;
	scanf("%d", &t);
	for (int k = 1; k <= t; k++) {
		scanf("%d", &n);
		maxC = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			dp[x] = dp[x - 1] + 1;
			maxC = max(maxC, dp[x]);
		}
		printf("#%d %d\n", k, n - maxC);
		memset(dp, 0, sizeof(dp[0])*(n + 1));
	}

	return 0;
}