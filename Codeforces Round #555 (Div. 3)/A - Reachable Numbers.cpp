#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	while (n / 10) {
		n++;
		cnt++;
		while (n % 10 == 0) {
			n /= 10;
		}
	}
	printf("%d", cnt + 9);

	return 0;
}