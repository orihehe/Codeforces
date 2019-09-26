#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int cnt[27];
int main() {
	int n, len, sum, mv;
	char st[101];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", st);
		len = strlen(st);
		mv = 27;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < len; i++) {
			if (cnt[st[i] - 'a'] != 0) {
				printf("No\n");
				mv = 27;
				break;
			}
			cnt[st[i] - 'a']++;
			mv = min(mv, st[i] - 'a');
		}
		for (int i = mv; i < 27; i++) {
			if (cnt[i]) {
				len -= cnt[i];
			}
			else {
				if (len > 0) printf("No\n");
				else printf("Yes\n");
				break;
			}
		}
	}

	return 0;
}