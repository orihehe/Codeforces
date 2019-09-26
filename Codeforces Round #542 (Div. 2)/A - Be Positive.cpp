#include <cstdio>
using namespace std;

/* 🐣🐥 */
int n, x, mc, cc;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x > 0) mc++;
		else if (x < 0)cc++;
	}
	if (mc >= (n + 1) / 2) printf("1");
	else if (cc >= (n + 1) / 2) printf("-1");
	else printf("0");

	return 0;
}