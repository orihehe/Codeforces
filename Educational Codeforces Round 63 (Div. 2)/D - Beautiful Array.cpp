/*
구간을 0, 1, 2로 나누어 풀어준다.
0은 구간 선택 전, 1은 구간 선택 후, 2는 구간 선택 후 구간 닫음
dp배열을 저렇게 설정 후 연속합(BOJ 1912) 처럼 풀어준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll dp[300001][3], arr[300001], ans;
int n, x;
ll go(int cur, int w) {
	if (cur == n) return 0;
	if (dp[cur][w] != -1) return dp[cur][w];

	ll ret, num;
	ret = go(cur + 1, w);
	if (w != 2) 
		ret = max(go(cur + 1, w + 1), ret);
	num = w == 1 ? x*arr[cur] : arr[cur];

	dp[cur][w] = max(ret + num, 1LL * 0);
	ans = max(dp[cur][w], ans);

	return dp[cur][w];
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	go(0, 0);
	go(0, 1);
	printf("%lld", ans);

	return 0;
}