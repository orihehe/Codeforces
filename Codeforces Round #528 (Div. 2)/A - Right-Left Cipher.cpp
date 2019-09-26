#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char st[51];
	scanf("%s", &st);
	int len = strlen(st);
	int x = len / 2 - 1, y = len / 2;
	if (len % 2 == 1) {
		printf("%c", st[len / 2]);
		y++;
		while (x >= 0) {
			printf("%c%c", st[y], st[x]);
			x--; y++;
		}
	}
	while (x >= 0) {
		printf("%c%c", st[x], st[y]);
		x--; y++;
	}

	return 0;
}