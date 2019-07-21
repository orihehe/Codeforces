#include <cstdio>
#define ll long long
#define mod 998244353
using namespace std;

/* 🐣🐥 */
int main() {
	int w, h;
	ll ans = 1;
	scanf("%d %d", &w, &h);
	w += h;
	while (w--) {
		ans = ans * 2 % mod;
	}
	printf("%lld", ans);

	return 0;
}