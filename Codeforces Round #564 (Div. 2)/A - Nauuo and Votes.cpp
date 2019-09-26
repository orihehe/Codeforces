#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int a, b, c, cur;
	scanf("%d %d %d", &a, &b, &c);
	cur = a - b;
	if (cur == 0 && c == 0) printf("0");
	else if (cur > 0 && cur > c) printf("+");
	else if (cur<0 && -cur > c) printf("-");
	else printf("?");

	return 0;
}