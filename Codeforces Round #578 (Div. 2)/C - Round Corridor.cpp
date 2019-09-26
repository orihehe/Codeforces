#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll gcd(ll x, ll y) {
	ll tmp;
	if (y > x) swap(x, y);
	while (y > 0) {
		tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}
int main() {
	ll n, m, sx, sy, ex, ey;
	int q;
	scanf("%lld %lld %d", &n, &m, &q);
	ll gg = gcd(n, m);
	while (q--) {
		scanf("%lld %lld %lld %lld", &sx, &sy, &ex, &ey);
		sy--; ey--;
		ll a, b;
		if (sx == 1) a = n / gg;
		else a = m / gg;
		if (ex == 1) b = n / gg;
		else b = m / gg;
		if (sy / a == ey / b) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}