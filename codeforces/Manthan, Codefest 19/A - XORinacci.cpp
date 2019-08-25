#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, a, b, c;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d %d", &a, &b, &c);
		if (c % 3 == 0) 
			printf("%d", a);
		else if (c % 3 == 1) 
			printf("%d", b);
		else 
			printf("%d", b^a);
		printf("\n");
	}

	return 0;
}