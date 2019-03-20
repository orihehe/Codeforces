/*
한 주기의 합과, 그 주기중 가장 작은 값을 저장해둔다.
만약 합이 0이상이라면 주기중 최솟값으로 h를 깎을 수 없다면 전투가 끝나지 않고,
그렇지 않다면 h에서 최솟값(음수)을 더한값에 몇번의 주기가 필요한지를 계산해준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[200000];
int main() {
	ll h, mn = 1000000000000, sum = 0, ans;
	int n;
	scanf("%lld %d", &h, &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		sum += arr[i];
		mn = min(mn, sum);
	}
	if (h + mn > 0 && sum >= 0) printf("-1");
	else {
		if (h + mn <= 0) {
			ans = 0;
		}
		else {
			sum = -sum;
			ans = (h + mn + sum - 1) / sum;
			sum = -sum;
			h += ans * sum;
		}
		int cnt;
		for (cnt = 0; cnt < n; cnt++) {
			if (h <= 0) break;
			h += arr[cnt];
		}
		printf("%lld", ans*n + cnt);
	}

	return 0;
}