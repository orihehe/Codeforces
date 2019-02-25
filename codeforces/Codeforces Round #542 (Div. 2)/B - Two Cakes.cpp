/*
현재 각 지점을 a,b라 하고, 목적지가 a', b'라면
a->a' + b->b' / a->b' + b->a' 중 작은 값을 골라야 한다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[200001];
int n;
ll a, b, ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n * 2; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n * 2);
	ans = arr[0].second + arr[1].second;
	for (int i = 2; i < n * 2; i += 2) {
		if (abs(arr[i - 2].second - arr[i].second) +
			abs(arr[i - 1].second - arr[i + 1].second) >
			abs(arr[i - 1].second - arr[i].second) +
			abs(arr[i - 2].second - arr[i + 1].second)) {
			ans += abs(arr[i - 1].second - arr[i].second) +
				abs(arr[i - 2].second - arr[i + 1].second);
		}
		else {
			ans += abs(arr[i - 2].second - arr[i].second) +
				abs(arr[i - 1].second - arr[i + 1].second);
		}
	}
	printf("%lld", ans);

	return 0;
}