#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
bool suc[10];
int main() {
	int l, r;
	scanf("%d %d", &l, &r);
	for (int i = l; i <= r; i++) {
		int tmp = i;
		memset(suc, false, sizeof(suc));
		bool flag = true;
		while (tmp) {
			if (suc[tmp % 10]) flag = false;
			suc[tmp % 10] = true;
			tmp /= 10;
		}
		if (flag) return !printf("%d", i);
	}
	printf("-1");

	return 0;
}