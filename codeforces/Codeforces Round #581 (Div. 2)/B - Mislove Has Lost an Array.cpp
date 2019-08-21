#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, l, r;
	int mn = 0, mx = 0;
	scanf("%d %d %d", &n, &l, &r);
	int sm = l - 1, tmp = 2;
	for (int i = 0; i < sm; i++) {
		mn += tmp;
		tmp *= 2;
	}
	mn += n - sm;
	tmp = 1;
	for (int i = 0; i < r - 1; i++) {
		mx += tmp;
		tmp *= 2;
	}
	mx += (n - r + 1) * tmp;
	printf("%d %d", mn, mx);

	return 0;
}
