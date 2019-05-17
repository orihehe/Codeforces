/*
small to large

작은 수부터 넣어주면서 그 수의 위치의 양쪽 바로 옆에 집합이 있다면 
현재 수를 최댓값으로 하는 쌍이 생길 수 있다.
바로 옆에 집합이 없다면 사이에 본인보다 큰 수가 들어오기 때문에 쌍이 생길 수 없음.
*/
#include <cstdio>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[200002], idx[200002];
set<int> sss[200002];
int p[200002];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[b] = a;
}
int main() {
	int n;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		idx[arr[i]] = i;
		p[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int cur = idx[i], l, r;
		l = find(cur - 1), r = find(cur + 1);
		if (sss[l].size() < sss[r].size()) swap(l, r);
		if (sss[l].size() > 0 && sss[r].size() > 0) { // 쌍 존재
			for (auto iter = sss[r].begin(); iter != sss[r].end(); iter++) {
				auto ii = sss[l].lower_bound(i - *iter);
				if (*ii == i - *iter) {
					ans++;
				}
			}

			sss[l].insert(i);
			for (auto iter = sss[r].begin(); iter != sss[r].end(); iter++) {
				sss[l].insert(*iter);
			}
			merge(l, r);
			merge(l, cur);
			sss[r].clear();
		}
		else if (sss[l].size() > 0) {
			merge(l, cur);
			sss[l].insert(i);
		}
		else {
			sss[cur].insert(i);
		}
	}
	printf("%lld", ans);

	return 0;
}