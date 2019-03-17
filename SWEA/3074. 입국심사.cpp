/*
SWEA 3074. 입국심사

이분탐색을 통해 시간을 정해두고, 
그 시간에 각 심사대에서 심사할 수 있는 명수를 구할 수 있다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[100001], l, r, mid, m, cnt, ans;
int main() {
	int t, n;
	scanf("%d", &t);
	for (int k = 1; k <= t; k++) {
		scanf("%d %lld", &n, &m);
		for (int i = 0; i < n; i++) 
			scanf("%lld", &arr[i]);
		l = 1, r = 1000000000000000000;
		while (l <= r) {
			mid = (l + r) / 2;
			cnt = 0;
			for (int i = 0; i < n; i++) {
				cnt += mid / arr[i];
			}
			if (cnt >= m) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		printf("#%d %lld\n", k, ans);
	}

	return 0;
}