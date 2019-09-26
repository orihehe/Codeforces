#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
char b[2002][2003];
int dp1[4004][4004], dp2[4004][4004];
int main() {
	int n, k, cnt = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", b[i] + 1);
	}
	for (int i = 1; i <= n; i++) {
		int s = 2002, e = 0;
		for (int j = 1; j <= n; j++) {
			if (b[i][j] == 'B') {
				s = min(j, s);
				e = max(e, j);
			}
		}
		if (s == 2002) {
			cnt++;
		}
		else if (e - s + 1 <= k) {
			dp1[i][s + 1]--;
			dp1[i][max(1, e - k + 1)]++;
		}

		s = 2002, e = 0;
		for (int j = 1; j <= n; j++) {
			if (b[j][i] == 'B') {
				s = min(j, s);
				e = max(e, j);
			}
		}
		if (s == 2002) {
			cnt++;
		}
		else if (e - s + 1 <= k) {
			dp2[s + 1][i]--;
			dp2[max(1, e - k + 1)][i]++;
		}
	}
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= n + 1; j++)
			dp1[i][j] += dp1[i][j - 1];
	}
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= n + 1; j++)
			dp2[i][j] += dp2[i - 1][j];
	}

	for (int i = 1; i <= n + 1; i++) {
		for (int j = n - 1; j >= 1; j--)
			dp1[j][i] += dp1[j + 1][i];
	}
	for (int i = 1; i <= n + 1; i++) {
		for (int j = n - 1; j >= 1; j--)
			dp2[i][j] += dp2[i][j + 1];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			ans = max(ans, dp1[i][j] - dp1[i + k][j] + dp2[i][j] - dp2[i][j + k]);
	}
	printf("%d", ans + cnt);

	return 0;
}