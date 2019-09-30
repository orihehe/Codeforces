#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
bool sosu[32000];
vector<ll> vec;
ll calc(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) ret = ret * x %mod;
		x = x * x%mod;
		y /= 2;
	}
	return ret;
}
int main() {
	ll x, n, ans = 1;
	scanf("%lld %lld", &x, &n);
	for (int i = 2; i < 32000; i++) {
		while (x%i == 0) {
			vec.push_back(i);
			x /= i;
		}
	}
	if (x != 1) vec.push_back(x);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int v : vec) {
		ll num = 0, nn = n;
		while (nn/v) {
			num += nn / v;
			nn /= v;
		}
		ans = ans * calc(v, num)%mod;
	}
	printf("%lld", ans);

	return 0;
}