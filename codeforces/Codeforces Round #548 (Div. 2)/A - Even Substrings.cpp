#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int main() {
	int n;
	ll ans = 0;
	char st[65001];
	scanf("%d", &n);
	scanf("%s", st);
	for (int i = 0; i < n; i++) {
		if ((st[i] - '0') % 2 == 0) {
			ans += i + 1;
		}
	}
	printf("%lld", ans);

	return 0;
}