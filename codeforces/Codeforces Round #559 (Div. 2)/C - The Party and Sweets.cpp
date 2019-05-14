/*
각 소년이 선물하는 사탕 수의 최솟값이 존재해야하니
우선은 모두 bi로 준다고 생각하고, m-1개만큼 map에 추가하여 더 줄 후보를 만들어준다.
g를 큰 순으로 정렬 하고, gi에 대해 나 이하의 수에서의 최댓값을 찾아 답에 차이를 더해줬다.
*/
#include <cstdio>
#include <algorithm>
#include <map>
#define ll long long
#define MAX 100000000
using namespace std;

/* 🐣🐥 */
int by[100001], gr[100001], bm, gm;
map<int, ll> mp;
int main() {
	int n, m;
	ll ans = 0;
	scanf("%d %d", &n, &m);
	bm = 0, gm = MAX;;
	for (int i = 0; i < n; i++) {
		scanf("%d", &by[i]);
		ans += 1LL * by[i] * m;
		mp[by[i]] += m - 1;
		bm = max(by[i], bm);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &gr[i]);
		gm = min(gr[i], gm);
	}
	if (gm < bm) return !printf("-1");
	sort(gr, gr + m, greater<int>());
	sort(by, by + n);
	for (int i = 0; i < m; i++) {
		int idx = lower_bound(by, by + n, gr[i]) - by;
		if (idx != n && gr[i] == by[idx]) continue;
		auto iter = mp.upper_bound(gr[i]);
		iter--;
		ans += gr[i] - iter->first;
		iter->second--;
		if (iter->second == 0) mp.erase(iter);
	}
	printf("%lld", ans);

	return 0;
}