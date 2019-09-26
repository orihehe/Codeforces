#include <cstdio>
using namespace std;

int main() {
	int n, k, x, sum = 0;
	scanf("%d %d", &n, &k);
	for (int i = k - 1; i > 0; i--) {
		scanf("%d", &x);
		if (x % 2 == 1 && n % 2 == 1) {
			sum++;
		}
	}
	scanf("%d", &x);
	if (x % 2 == 1) sum++;
	printf("%s", sum % 2 ? "odd" : "even");

	return 0;
}