#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[103];
int main() {
	int cnt = 0;
	scanf("%s", st);
	int len = strlen(st);
	if (len % 2 == 0) return !printf("%d", len / 2);
	for (int i = 1; i < len; i++) {
		if (st[i] - '0') cnt++;
	}
	printf("%d", len / 2 + (cnt != 0));

	return 0;
}