#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[1000002], tt[1000002];
int fail[1000001];
int main() {
	int n, len, ori;
	scanf("%d", &n);
	n--;
	scanf("%s", st);
	ori = strlen(st);
	while (n--) {
		scanf("%s", tt);
		len = strlen(tt);
		int k = max(0, ori - len);
		for (int i = 1, j = 0; i < len; i++) {
			while (j > 0 && tt[i] != tt[j]) j = fail[j - 1];
			if (tt[i] == tt[j]) fail[i] = ++j;
			else fail[i] = 0;
		}
		int j = 0;
		for (int i = k; i < ori; i++) {
			while (j > 0 && st[i] != tt[j]) j = fail[j - 1];
			if (j < len && st[i] == tt[j]) j++;
		}
		for (int i = j; i < len; i++) {
			st[ori++] = tt[i];
		}
	}
	printf("%s", st);

	return 0;
}