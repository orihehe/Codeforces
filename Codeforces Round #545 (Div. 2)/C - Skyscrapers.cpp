#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int b[1001][1001];
int r[1001][1001], rn[1001][1001];
int c[1001][1001], cn[1001][1001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &b[i][j]);
			r[i][j] = c[j][i] = b[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		sort(r[i], r[i] + m);
		rn[i][0] = 1;
		for (int j = 1; j < m; j++)
			rn[i][j] = rn[i][j - 1] + (r[i][j] == r[i][j - 1] ? 0 : 1);
	}
	for (int i = 0; i < m; i++) {
		sort(c[i], c[i] + n);
		cn[i][0] = 1;
		for (int j = 1; j < n; j++)
			cn[i][j] = cn[i][j - 1] + (c[i][j] == c[i][j - 1] ? 0 : 1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ii = lower_bound(r[i], r[i] + m, b[i][j]) - r[i];
			int jj = lower_bound(c[j], c[j] + n, b[i][j]) - c[j];
			if (rn[i][ii] > cn[j][jj]) printf("%d ", max(rn[i][m - 1], cn[j][n - 1] + rn[i][ii] - cn[j][jj]));
			else printf("%d ", max(cn[j][n - 1], rn[i][m - 1] + cn[j][jj] - rn[i][ii]));
		}
		printf("\n");
	}

	return 0;
}