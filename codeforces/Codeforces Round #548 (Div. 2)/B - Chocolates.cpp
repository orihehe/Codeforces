/*
자신보다 앞의 값보다 무조건 큰 값을 사야한다.
따라서 뒤에서부터 최대한 많이 사준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[200001];
int main() {
	int n, l = 1000000001;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] >= l) {
			ans += max(0, l - 1);
			l--;
		}
		else {
			ans += arr[i];
			l = arr[i];
		}
	}
	printf("%lld", ans);

	return 0;
}