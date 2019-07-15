#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char a[101], b[101], c[101];
int num[128];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(num, 0, sizeof(num));
		scanf("%s %s %s", a, b, c);
		int cl = strlen(c), al = strlen(a), bl = strlen(b);
		int ap = 0, bp = 0, cp = 0;
		for (int i = 0; i < cl; i++) {
			num[c[i]]++;
		}
		bool suc = true;
		for (int i = 0; i < bl; i++) {
			if (ap == al) {
				if (num[b[i]]) {
					num[b[i]]--;
					continue;
				}
				else {
					suc = false;
					break;
				}
			}
			if (a[ap] == b[i]) {
				ap++;
				continue;
			}
			else {
				if (num[b[i]]) {
					num[b[i]]--;
				}
				else {
					suc = false;
					break;
				}
			}
		}
		if (ap != al) suc = false;
		if (suc) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}