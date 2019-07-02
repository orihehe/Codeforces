#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, m, k, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		if (m > k) swap(k, m);
		printf("%d\n", n - m + 1);
	}

	return 0;
}