/*
l-1까지의 짝,홀 개수와 r까지의 짝,홀 개수를 구하여 그 합을 구해준다.
그리고나서 r합-(l-1)합 을 출력
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
ll calc(ll num) {
	ll x = 1, e = 0, o = 0;
	for (int i = 1; i < 65; i++) {
		if (num <= 0) break;
		if (i % 2) {
			o += min(x, num);
		}
		else {
			e += min(x, num);
		}
		num -= x;
		x *= 2;
	}
	e %= mod, o %= mod;
	e = (e * e%mod + e) % mod;
	o = o * o%mod;
	e = (e + o) % mod;
	return e;
}
int main() {
	ll l, r;
	scanf("%lld %lld", &l, &r);
	l--;
	printf("%lld", (calc(r) - calc(l) + mod) % mod);

	return 0;
}