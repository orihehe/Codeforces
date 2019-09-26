#include <cstdio>
#include <algorithm>
#include <map>
#define ll long long
#define pii pair<int,int>
#define mod 998244353
using namespace std;

/* 🐣🐥 */
ll calc(int n) {
	ll ret = 1;
	while (n > 1) {
		ret *= n;
		n--;
		ret %= mod;
	}
	return ret;
}
int l[300001], r[300001];
map<pii, int> mp;
pii arr[300001];
int main() {
	ll ans, mn1 = 1, mn2 = 1, mn3 = 1;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		l[arr[i].first]++, r[arr[i].second]++;
		mp[arr[i]]++;
	}
	sort(arr, arr + n);
	bool flag = true;
	for (int i = 1; i < n; i++) {
		if (arr[i].second < arr[i - 1].second) flag = false;
	}
	ans = calc(n);
	for (int i = 1; i <= n; i++) {
		mn1 *= calc(l[i]);
		mn1 %= mod;
	}
	for (int i = 1; i <= n; i++) {
		mn2 *= calc(r[i]);
		mn2 %= mod;
	}
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		mn3 *= calc(iter->second);
		mn3 %= mod;
	}
	printf("%lld", (ans - mn1 - mn2 + (flag ? mn3 : 0) + mod * 2LL) % mod);

	return 0;
}