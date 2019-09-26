#include <cstdio>
using namespace std;

int main() {
	int l, r, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &l, &r);
		printf("%d %d\n", l, l * 2);
	}

	return 0;
}