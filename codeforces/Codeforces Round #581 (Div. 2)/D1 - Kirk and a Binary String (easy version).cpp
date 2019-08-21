#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 1000000000
using namespace std;

/* 🐣🐥 */
char st[2001];
int ori[2001][2001];
int o[2001], z[2001], p[2001];
int c[2001];
int mx[2001];
int main() {
	scanf("%s", st + 1);
	int len = strlen(st + 1);
	for (int i = 1; i <= len; i++) {
		o[i] = o[i - 1];
		z[i] = z[i - 1];
		if (st[i] == '1') o[i]++;
		else z[i]++;
	}
	for (int i = 1; i <= len; i++) {
		for (int j = i; j <= len; j++) {
			ori[i][j] = max(ori[i][j - 1] + (st[j] == '1'), o[j] - o[i - 1]);
			ori[i][j] = max(ori[i][j], z[j] - z[i - 1]);
			if (z[j] - z[i - 1] == ori[i][j]) mx[i] = j;
		}
	}
	fill(p, p + len + 1, INF);
	for (int i = 1; i <= len; i++) {
		if (st[i] == '0') continue;
		int mn = INF;
		for (int j = i; j <= len; j++) {
			p[j] = min(p[j], ori[i][j] - (z[j] - z[i - 1]));
			mn = min(p[j], mn);
		}
		if (mn > 0) {
			st[i] = '0';
			for (int j = i; j <= len; j++) {
				p[j]--;
			}
		}
	}
	printf("%s", st + 1);

	return 0;
}