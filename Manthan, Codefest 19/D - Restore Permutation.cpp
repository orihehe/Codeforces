#include <cstdio>
#include <algorithm>
#define ll long long
#define INF 19999999999
using namespace std;

/* 🐣🐥 */
ll arr[200001];
ll lazy[524288], tree[524288], val;
int n, ans[200001];
void update(int idx, int s, int e, int l, int r) {
	if (s > r || e < l) return;
	if (l <= s && e <= r) {
		lazy[idx] -= val;
		return;
	}
	update(idx * 2, s, (e + s) / 2, l, r);
	update(idx * 2 + 1, (e + s) / 2 + 1, e, l, r);
	tree[idx] = min(tree[idx * 2] + lazy[idx * 2],
		tree[idx * 2 + 1] + lazy[idx * 2 + 1]);
}
int find(int idx, int s, int e, ll sum) {
	sum += lazy[idx];
	if (s == e) {
		return s;
	}
	if (tree[idx * 2 + 1] + lazy[idx * 2 + 1] + sum == 0)
		return find(idx * 2 + 1, (e + s) / 2 + 1, e, sum);
	else return find(idx * 2, s, (e + s) / 2, sum);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		val = -arr[i];
		update(1, 0, n, i, i);
	}
	val = -INF;
	update(1, 0, n, n, n);
	for (int i = 1; i <= n; i++) {
		int idx = find(1, 0, n, 0);
		ans[idx] = i;
		val = -INF;
		update(1, 0, n, idx, idx);
		val = i;
		update(1, 0, n, idx + 1, n);
	}
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);

	return 0;
}