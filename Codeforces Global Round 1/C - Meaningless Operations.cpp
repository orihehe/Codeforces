/*
입력 받는 수(a)가 2^n-1꼴이라면 그 수의 가장 작은 소인수로 나눈 수를 b로 설정,
그렇게되면 a는 b의 배수가 되므로 gcd값은 b가 된다.
그렇지 않다면 2^a비트수 출력
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;

ll isPrime(ll n) {
	ll sn = (ll)sqrt(n);
	for (ll i = 2; i <= sn; i++) {
		if (n%i == 0) return i;
	}
	return 1;
}
int main() {
	int q;
	ll a, tmp, ra, rb, l;
	scanf("%d", &q);
	while (q--) {
		tmp = l = 0;
		scanf("%lld", &a);
		for (ll i = 1; i <= a; i *= 2) {
			if ((a | i) != a) {
				tmp += i;
			}
		}
		if (tmp == 0) {
			rb = isPrime(a);
			printf("%lld\n", rb==1 ? rb : a/rb);
		}
		else {
			ra = tmp ^ a;
			printf("%lld\n", ra);
		}
	}

	return 0;
}