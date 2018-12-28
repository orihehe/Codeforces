#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n, len, x = 0;
	char st[10000];
	scanf("%d", &n);
	scanf("%s", st);
	len = strlen(st);
	for (int i = 0; i < len; i += x) {
		printf("%c", st[i]);
		x++;
	}

	return 0;
}