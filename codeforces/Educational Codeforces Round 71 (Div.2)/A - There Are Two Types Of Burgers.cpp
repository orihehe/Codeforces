#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, b, p, f, h, c, ans;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d %d %d %d", &b, &p, &f, &h, &c);
		if (c > h) {
			swap(h, c);
			swap(p, f);
		}
		int num = min(b / 2, p);
		ans = num * h;
		b -= num * 2;
		ans += min(b / 2, f)*c;
		printf("%d\n", ans);
	}

	return 0;
}