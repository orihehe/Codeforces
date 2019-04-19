#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, ans = 5000, tmp, u, d;
	char st[52];
	scanf("%d", &n);
	scanf("%s", st);
	for (int i = 0; i <= n - 4; i++) {
		tmp = 0;
		tmp += min((st[i] - 'A' + 26) % 26, ('A' - st[i] + 26) % 26);
		tmp += min((st[i + 1] - 'C' + 26) % 26, ('C' - st[i + 1] + 26) % 26);
		tmp += min((st[i + 2] - 'T' + 26) % 26, ('T' - st[i + 2] + 26) % 26);
		tmp += min((st[i + 3] - 'G' + 26) % 26, ('G' - st[i + 3] + 26) % 26);
		ans = min(ans, tmp);
	}
	printf("%d", ans);

	return 0;
}