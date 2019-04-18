/*젖
가치를 기준으로 냅색, 작은 무게를 저장
*/
#include <cstdio>
#include <algorithm>
#define MAX 1000000001
using namespace std;

/* 🐣🐥 */
int dp[100001], b, ans;
int main() {
	int n, w, a;
	scanf("%d %d", &n, &w);
	fill(dp, dp + 100001, MAX);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (int j = 100000; j >= b; j--) {
			if (dp[j - b] != -1 && dp[j - b] + a <= w) {
				dp[j] = min(dp[j], dp[j - b] + a);
			}
		}
	}
	for (int i = 100000; i >= 0; i--) if (dp[i] != MAX) return !printf("%d", i);

	return 0;
}