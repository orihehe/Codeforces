#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
int main() {
	int q;
	ll k, n, a, b;
	scanf("%d", &q);
	while (q--) {
		scanf("%lld %lld %lld %lld", &k, &n, &a, &b);
		if (b*n >= k) printf("-1\n");
		else {
			k -= b * n;
			printf("%lld\n", min(n, (k - 1) / (a - b)));
		}
	}

	return 0;
}