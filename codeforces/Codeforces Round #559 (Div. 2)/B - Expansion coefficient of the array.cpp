/*
|i-j| 가 하나씩 줄어들 때 마다 최솟값이 될 수 있는 수가 양쪽에서 하나씩 더 추가된다.
따라서 |i-j|를 줄여가며 최솟값을 구한 뒤 k를 갱신해준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[300001];
int main() {
	int n, mn = 1000000000, l, r;
	ll k = 1000000000;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	l = 0, r = n - 1;
	for (int i = n - 1; i >= n / 2; i--) {
		mn = min({ mn,arr[l],arr[r] });
		k = min(k, (ll)(mn / i));
		l++, r--;
	}
	printf("%lld", k);

	return 0;
}