#include <cstdio>
#include <algorithm>
#include <queue>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[200001];
priority_queue<int> pq;
int main() {
	int q, n, x, f;
	ll ans = 0, w = 0;
	scanf("%d", &q);
	while (q--) {
		ans = 0, w = 0;
		while (!pq.empty()) pq.pop();
		scanf("%d", &n);
		fill(arr, arr + n + 1, pii(0, 0));

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &f);
			arr[x].first++;
			if (f) arr[x].second++;
		}
		sort(arr, arr + n + 1, greater<pii>());
		int ap = 0;
		for (int i = n; i >= 1; i--) {
			while (arr[ap].first == i) {
				pq.push(arr[ap].second);
				ap++;
			}
			if (!pq.empty()) {
				ans += i;
				w += min(i, pq.top());
				pq.pop();
			}
		}
		printf("%lld %lld\n", ans, w);
	}

	return 0;
}