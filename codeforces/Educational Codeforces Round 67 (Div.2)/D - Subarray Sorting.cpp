#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
#define pii pair<int,int>
#define MAX 1000000000
using namespace std;

/* 🐣🐥 */
int num[300001], tree[1048576];
pii arr[300001];
priority_queue<pii> pq;
void init(int idx, int s, int e) {
	tree[idx] = MAX;
	if (s == e) return;
	init(idx * 2, s, (s + e) / 2);
	init(idx * 2 + 1, (s + e) / 2 + 1, e);
}
void update(int idx, int s, int e, int k, int val) {
	if (k > e || k < s) return;
	tree[idx] = val;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}
int mx(int idx, int s, int e, int l, int r) {
	if (s > r || e < l) return MAX;
	if (l <= s && e <= r) return tree[idx];
	return min(mx(idx * 2, s, (s + e) / 2, l, r),
		mx(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main() {
	int t, n, a;
	scanf("%d", &t);
	while (t--) {
		bool suc = true;
		scanf("%d", &n);
		fill(num, num + n + 1, 0);
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i].first);
			num[arr[i].first]++;
			arr[i].second = i;
		}
		sort(arr, arr + n, greater<pii>());
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			num[a]--;
			if (num[a] < 0) suc = false;
			pq.push({ a,i });
		}
		if (!suc) {
			printf("NO\n");
			continue;
		}
		init(1, 0, n - 1);
		for (int i = 0; i < n; i++) {
			pii cur = pq.top();
			pq.pop();
			int xx = mx(1, 0, n - 1, arr[i].second, n - 1);
			if (xx < cur.second) {
				suc = false;
			}
			update(1, 0, n - 1, arr[i].second, cur.second);
		}
		if (!suc) {
			printf("NO\n");
		}
		else printf("YES\n");
	}

	return 0;
}
