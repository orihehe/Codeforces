#include <cstdio>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[100001];
bool cmp(pii &a, pii &b) {
	return a.second - a.first < b.second - b.first;
}
int main() {
	int n, a, b;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		arr[i] = { a,b };
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		ans += 1LL * arr[i].first*i + 1LL * arr[i].second*(n - i - 1);
	}
	printf("%lld", ans);

	return 0;
}