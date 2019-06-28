/*
dp[인덱스][길이] - 현재 인덱스의 글자를 마지막으로 하는 x길이의 subsequence개수를 저장
이것은 x-1길이의 가장 가까운 a,b,c,...,y,z로 끝나는 개수의 합과 같다
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll dp[101][101];
bool use[26];
char st[101];
int main() {
	int n;
	ll kk, ans = 0, cnt = 0;
	scanf("%d %lld %s", &n, &kk, st);
	for (int i = 0; i < n; i++) {
		dp[i][1] = 1;
		for (int j = 2; j <= i + 1; j++) { // 길이
			memset(use, false, sizeof(use));
			int tmp = 0;
			for (int k = i - 1; k >= 0; k--) {
				if (!use[st[k] - 'a'] && dp[k][j - 1] != 0) {
					use[st[k] - 'a'] = true;
					dp[i][j] += dp[k][j - 1];
					dp[i][j] = min(dp[i][j], kk);
				}
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		memset(use, false, sizeof(use));
		for (int j = n - 1; j >= 0; j--) {
			if (dp[j][i] != 0 && !use[st[j] - 'a']) {
				ans += min(kk - cnt, dp[j][i])*(n - i);
				cnt += dp[j][i];
				use[st[j] - 'a'] = true;
			}
			if (cnt >= kk) return !printf("%lld", ans);
		}
	}
	cnt++;
	ans += n;
	if (cnt < kk) printf("-1");
	else printf("%lld", ans);

	return 0;
}