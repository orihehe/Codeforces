/*
1리터의 가격, 2리터의 가격이 주어진다.
1리터 두 개의 가격과 2리터 한 개의 가격을 비교하여 계산해준다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int main() {
	ll t, a, b, c, cnt;
	scanf("%lld", &t);
	while (t--) {
		cnt = 0;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (2 * b >= c) {
			printf("%lld\n", c*(a / 2) + (a % 2 ? b : 0));
		}
		else {
			printf("%lld\n", a*b);
		}
	}

	return 0;
}