#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
char b[400001];
int rdp[50001], cdp[50001];
int main() {
	int t, r, c, ans;
	scanf("%d", &t);
	while (t--) {
		ans = INF;
		scanf("%d %d", &r, &c);
		fill(rdp, rdp + r, 0);
		fill(cdp, cdp + c, 0);
		for (int i = 0; i < r; i++) {
			scanf("%s", b + i * c);
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				rdp[i] += (b[i*c + j] == '.');
			}
		}
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				cdp[i] += (b[c*j + i] == '.');
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ans = min(ans, rdp[i] + cdp[j] - (b[i*c + j] == '.'));
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}