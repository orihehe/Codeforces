/*
먼저 b가 a의 배수인지 확인하고 b를 a로 나눠준 뒤
3과 2로 나누어 떨어지면 계속 나눠준다.
그 후 b가 1이 아니라면 a를 2와 3의 곱으로만 b를 만들 수 없다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int main() {
	ll a, b, s, cnt = 0;
	scanf("%lld %lld", &a, &b);
	if (b%a != 0) return !printf("-1");
	b /= a;
	while (b % 3 == 0) {
		cnt++;
		b /= 3;
	}
	while (b % 2 == 0) {
		cnt++;
		b /= 2;
	}
	if (b != 1) printf("-1");
	else printf("%lld", cnt);

	return 0;
}