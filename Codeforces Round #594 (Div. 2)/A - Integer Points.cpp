#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int num[2];
int main() {
	int n, t, x;
	ll ans;
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		num[0] = num[1] = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			num[x % 2]++;
		}
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			ans += num[x % 2];
		}
		printf("%lld\n", ans);
	}

	return 0;
}
