#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int main() {
	int a, b, c;
	ll ans = 0;
	scanf("%d %d %d", &a, &b, &c);
	ans = c * 2;
	if (a < b) {
		ans += a * 2;
		b -= a;
		if (b>0) ans++;
	}
	else {
		ans += b * 2;
		a -= b;
		if (a >0) ans++;
	}
	printf("%lld", ans);

	return 0;
}