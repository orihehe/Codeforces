/*
다음으로 작은 개최도시의 값만큼 현재 최소 개최도시에서 개최시킨다.
몇년까지 그 국가들로 개최하는지를 저장해두고, 
인덱스를 세그먼트트리로 관리하여 k번째 국가를 찾아준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;

/* 🐣🐥 */
pii city[500002];
pli year[500002], qu[500002];
int tree[1048576], ans[500002];
void update(int idx, int s, int e, int k) {
	if (s > k || e < k) return;
	tree[idx]++;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k);
}
int get(int idx, int s, int e, int k) {
	if (s == e) return s;
	if (tree[idx * 2] >= k) return get(idx * 2, s, (s + e) / 2, k);
	else return get(idx * 2 + 1, (s + e) / 2 + 1, e, k - tree[idx * 2]);
}
int main() {
	int n, m, q, x, mn, p;
	ll w;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= m; i++) city[i].second = i;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		city[x].first++;
	}
	sort(city + 1, city + m + 1);
	mn = city[1].first;
	year[0].first = n + 1; p = 0;
	for (int i = 1; i <= m; i++) {
		if (city[i].first == mn) continue;
		year[p].second = i - 1;
		p++;
		year[p].first = year[p - 1].first + 1LL * (i - 1) * (city[i].first - mn);
		mn = city[i].first;
	}
	year[p].second = m;
	p++;
	for (int i = 0; i < q; i++) {
		scanf("%lld", &w);
		qu[i] = { w,i };
	}
	sort(qu, qu + q);
	int last = 1;
	for (int i = 0; i < q; i++) {
		w = qu[i].first;
		int idx = lower_bound(year, year + p, pli(w, 0)) - year;
		if (year[idx].first != w) idx--;
		for (int j = last; j <= year[idx].second; j++) {
			update(1, 1, m, city[j].second);
		}
		last = year[idx].second + 1;

		w -= year[idx].first;
		ans[qu[i].second] = get(1, 1, m, w%year[idx].second + 1);
	}
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);

	return 0;
}