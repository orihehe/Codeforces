#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
int main() {
	ll x, y, z;
	scanf("%lld %lld %lld", &x, &y, &z);
	ll ans = 0, s = 0;
	ans += x / z;
	ans += y / z;
	x %= z; y %= z;
	if (x < y) swap(x, y);
	if (x + y >= z) {
		ans++;
		s = z - x;
	}
	printf("%lld %lld", ans, s);

	return 0;
}