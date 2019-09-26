#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int t, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		if (b % 3 == 0) {
			a %= (b + 1);
			if (b != a && a % 3 == 0) printf("Bob");
			else printf("Alice");
		}
		else {
			if (a % 3) printf("Alice");
			else printf("Bob");
		}
		printf("\n");
	}

	return 0;
}
