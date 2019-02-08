/*
�Է� �޴� ��(a)�� 2^n-1���̶�� �� ���� ���� ���� ���μ��� ���� ���� b�� ����,
�׷��ԵǸ� a�� b�� ����� �ǹǷ� gcd���� b�� �ȴ�.
�׷��� �ʴٸ� 2^a��Ʈ�� ���
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