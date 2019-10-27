#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[100001];
int main() {
	int n;
	ll ans = 0, x = 0, y = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n / 2; i++) x += arr[i];
	for (int i = n / 2; i < n; i++) y += arr[i];
	printf("%lld", x*x + y * y);

	return 0;
}