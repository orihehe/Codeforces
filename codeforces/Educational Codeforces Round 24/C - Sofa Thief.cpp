/*
l,r,t,b 에 대해 따로 좌표를 관리하여 모든 소파에 대해 각 방향의 개수를 세줬다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define MAX 100001
using namespace std;

/* 🐣🐥 */
vector<pii> r, l, u, d;
int cnt[100001];
int main() {
	int dd, n, m, x1, y1, x2, y2, cl, cr, cu, cd;
	scanf("%d %d %d", &dd, &n, &m);
	for (int i = 0; i < dd; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		r.push_back({ max(x1,x2),i });
		l.push_back({ min(x1,x2),i });
		u.push_back({ min(y1,y2),i });
		d.push_back({ max(y1,y2),i });
	}
	scanf("%d %d %d %d", &cl, &cr, &cu, &cd);
	sort(r.begin(), r.end());
	sort(l.begin(), l.end());
	sort(u.begin(), u.end());
	sort(d.begin(), d.end());
	for (pii v : r) {
		int tt = lower_bound(l.begin(), l.end(), pii(v.first-1,MAX)) - l.begin();
		int idx = lower_bound(l.begin(), l.end(), pii(v.first - 1, v.second)) - l.begin();
		if (idx != l.size() && l[idx] == pii(v.first-1,v.second)) tt--;
		if (tt == cl) cnt[v.second]++;
	}
	for (pii v : l) {
		int tt = r.end() - lower_bound(r.begin(), r.end(), pii(v.first+1, -1));
		int idx = lower_bound(r.begin(), r.end(), pii(v.first + 1, v.second)) - r.begin();
		if (idx != r.size() && r[idx] == pii(v.first + 1, v.second)) tt--;
		if (tt == cr) cnt[v.second]++;
	}
	for (pii v : d) {
		int tt = lower_bound(u.begin(), u.end(), pii(v.first-1, MAX)) - u.begin(); 
		int idx = lower_bound(u.begin(), u.end(), pii(v.first - 1, v.second)) - u.begin();
		if (idx != u.size() && u[idx] == pii(v.first - 1, v.second)) tt--;
		if (tt == cu) cnt[v.second]++;
	}
	for (pii v : u) {
		int tt = d.end() - lower_bound(d.begin(), d.end(), pii(v.first+1, -1));
		int idx = lower_bound(d.begin(), d.end(), pii(v.first + 1, v.second)) - d.begin();
		if (idx != d.size() && d[idx] == pii(v.first + 1, v.second)) tt--;
		if (tt == cd) cnt[v.second]++;
	}
	for (int i = 0; i < dd; i++) {
		if (cnt[i] == 4) return !printf("%d", i+1);
	}
	printf("-1");

	return 0;
}