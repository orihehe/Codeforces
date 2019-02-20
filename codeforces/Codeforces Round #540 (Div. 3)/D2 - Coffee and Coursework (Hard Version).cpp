/*
큰 값의 커피를 먼저 마시는게 이득
이분탐색의 mid값을 일하는 날 수로 잡고 커피를 마셨을 때
m의 일을 할 수 있는지 없는지로 mid값을 변경해준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[200001], m, ss, sum, ans, cnt, mm;
int main() {
	int n, l, r, mid;
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		ss += arr[i];
	}
	if (ss < m) return !printf("-1");
	sort(arr, arr + n);
	ans = n;
	l = 1, r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0; mm = 0; sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			sum += max(arr[i] - mm, (ll)0);
			cnt++;
			if (cnt == mid) {
				mm++;
				cnt = 0;
			}
		}
		if (sum >= m) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	printf("%lld", ans);

	return 0;
}