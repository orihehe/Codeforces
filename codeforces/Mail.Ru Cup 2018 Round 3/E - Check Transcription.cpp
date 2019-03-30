/*
0에 해당하는 길이를 정하고, 그에 따른 1의 길이를 정할 수 있을 때 그 경우를 봐준다.
*/
#include <cstdio>
#include <cstring>
#define ll long long
#define mod1 1000000009
#define mod2 1000000021
using namespace std;

/* 🐣🐥 */
char st[100002], tt[1000002];
ll jin[2][1000001], wprhq[2][1000001], loc[2], h[2];
ll hs(ll fr, ll ba) {
	ll tmp1 = (jin[0][fr] - jin[0][ba] + mod1) % mod1 * wprhq[0][ba] % mod1;
	ll tmp2 = (jin[1][fr] - jin[1][ba] + mod2) % mod2 * wprhq[1][ba] % mod2;
	return tmp1 * mod2 + tmp2;
}
int main() {
	int n, m;
	ll x = 1, y = 1, sum = 0, ans = 0, cnt0 = 0, cnt1 = 0;
	scanf("%s %s", st + 1, tt + 1);
	n = strlen(st + 1);
	m = strlen(tt + 1);
	for (int i = 1; i <= n; i++) {
		if (st[i] == '0') {
			cnt0++;
			if (!loc[0]) loc[0] = i;
		}
		else {
			cnt1++;
			if (!loc[1]) loc[1] = i;
		}
	}

	for (int i = 0; i < m; i++) {
		wprhq[0][i] = x;
		wprhq[1][i] = y;
		x = x * 127 % mod1;
		y = y * 127 % mod2;
	}
	for (int i = 1; i <= m; i++) {
		jin[0][i] = (jin[0][i - 1] + tt[i] * wprhq[0][m - i]) % mod1;
		jin[1][i] = (jin[1][i - 1] + tt[i] * wprhq[1][m - i]) % mod2;
	}
	for (int i = 1; i <= m; i++) { // 0의 길이 정해서
		ll rm = (m - cnt0 * i), len, last = 0; // 남은 길이
		if (rm <= 0 || rm % cnt1 != 0) continue;
		int j;
		if (loc[0] < loc[1]) { // 0이 먼저 나왔을 때
			ll yy = (loc[1] - loc[0])*i; // 연속한 앞의 0 마지막 위치
			h[0] = jin[0][i] * mod2 + jin[1][i];

			h[1] = hs(yy + rm / cnt1, yy);
		}
		else {
			ll yy = (loc[0] - loc[1])*rm / cnt1; // 연속한 앞의 1 마지막 위치
			h[1] = jin[0][rm / cnt1] * mod2 + jin[1][rm / cnt1];

			h[0] = hs(yy + i, yy);
		}
		if (h[0] == h[1]) continue;

		for (j = 1; j <= n; j++) {
			if (st[j] == '0') {
				len = i;
			}
			else {
				len = rm / cnt1;
			}
			if (hs(len+last,last) != h[st[j] - '0']) break;
			last += len;
		}
		if (j == n + 1) ans++;
	}
	printf("%lld", ans);

	return 0;
}