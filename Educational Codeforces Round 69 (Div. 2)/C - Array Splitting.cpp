#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[300001], cha[300001];
int n, k;
int main() {
	ll ans = 0;
	scanf("%d %d", &n, &k);
	scanf("%d", &arr[0]);
	for (int i = 1; i < n; i++) {
		scanf("%d", &arr[i]);
		cha[i] = arr[i] - arr[i - 1];
	}
	sort(cha + 1, cha + n);
	for (int i = 1; i <= n - k; i++) {
		ans += cha[i];
	}
	printf("%lld", ans);

	return 0;
}