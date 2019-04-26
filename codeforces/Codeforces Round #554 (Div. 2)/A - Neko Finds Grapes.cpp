#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int n, m, o, e, oo, ee, x;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x % 2) o++;
		else e++;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		if (x % 2) oo++;
		else ee++;
	}
	printf("%d", min(o, ee) + min(oo, e));

	return 0;
}