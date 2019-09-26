/*
간격들의 gcd를 구해서 그 약수인 값이 나오면 YES
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[300001];
ll x = 1000000000000000000, y, nn;
ll gcd(ll x, ll y) {
	ll tmp;
	if (y > x) swap(x, y);
	while (y > 0) {
		tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}
int main() {
	int n, m, ans = -1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	x = arr[1] - arr[0];
	for (int i = 2; i < n; i++) {
		x = gcd(x, arr[i] - arr[i - 1]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%lld", &y);
		if (x%y == 0) {
			printf("YES\n");
			printf("%lld %d", arr[0], i + 1);
			return 0;
		}
	}
	printf("NO");

	return 0;
}