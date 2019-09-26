#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
char st[200001];
int main() {
	int t, n;
	ll ans, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %lld %lld %s", &n, &a, &b, st);
		ans = 4 * b + 4 * a;

		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (st[i] == '1') flag = true;
		}
		if (!flag) {
			printf("%lld\n", n*a + (n + 1)*b);
			continue;
		}

		int s, e;
		for (s = 1; s < n; s++) {
			if (st[s] == '1') break;
			ans += b + a;
		}
		for (e = n - 2; e >= s; e--) {
			if (st[e] == '1') break;
			ans += b + a;
		}
		int cnt = 0;
		for (; s <= e; s++) {
			if (st[s] == '1') {
				ans += 2 * b + a;
				if (cnt) {
					cnt--;
					if (cnt) {
						ans += min(cnt*b + (cnt + 2) * a, cnt*a + cnt * 2 * b);
					}
					ans += b * 2 + a;
					cnt = 0;
				}
			}
			else {
				cnt++;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}