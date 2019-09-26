#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
char st[101];
int main() {
	int n, sum = 0, mn = 0;
	scanf("%d %s", &n, st);
	for (int i = 0; i < n; i++) {
		if (st[i] == '+') sum++;
		else {
			sum--;
			mn = min(mn, sum);
		}
	}
	printf("%d", sum - mn);

	return 0;
}