#include <cstdio>
#include <cmath>
using namespace std;

/* 🐣🐥 */
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2) printf("0");
	else printf("%d", (int)pow(2, n / 2));

	return 0;
}