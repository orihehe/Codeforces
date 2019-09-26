#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char a[1000001], b[1000001];
int aa, bb, ans;
int main() {
	scanf("%s %s", a, b);
	int alen = strlen(a), blen = strlen(b);
	for (int i = 0; i < blen; i++) {
		if (a[i] == '0') aa++;
		if (b[i] == '0') bb++;
	}
	if (aa % 2 == bb % 2) ans++;
	for (int i = blen; i < alen; i++) {
		aa += a[i] == '0' ? 1 : 0;
		aa += a[i - blen] == '0' ? -1 : 0;
		if (aa % 2 == bb % 2) ans++;
	}
	printf("%d", ans);

	return 0;
}