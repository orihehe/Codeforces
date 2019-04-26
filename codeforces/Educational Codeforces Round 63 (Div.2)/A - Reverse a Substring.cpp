/*
현재 문자보다 작은 문자가 나오면 무조건 가능하다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char st[300001];
int main() {
	int n, l = 0, r = 0;
	char x, y;
	scanf("%d", &n);
	scanf("%s", st);
	x = st[0];
	for (int i = 1; i < n; i++) {
		if (st[i] < x) {
			r = i;
			break;
		}
		else {
			x = st[i];
			l = i;
		}
	}
	if (st[r] >= x || r == 0) printf("NO");
	else printf("YES\n%d %d", l + 1, r + 1);

	return 0;
}