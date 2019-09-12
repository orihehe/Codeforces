#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define pii pair<int,int>
#define mod 1000000007
#define INF 1000000000
using namespace std;

/* 🐣🐥 */
pii arr[200001];
int mx[1048576], hap[1048576];
vector<int> loc, iin;
void update(int idx, int s, int e, int k, int val, int num) {
	if (k<s || k>e) return;
	if (s == e) {
		if (val < mx[idx]) {
			mx[idx] = val;
			hap[idx] = num;
		}
		else if (val == mx[idx])
			hap[idx] = (hap[idx] + num) % mod;
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, val, num);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val, num);
	if (mx[idx * 2] == mx[idx * 2 + 1]) hap[idx] = (hap[idx * 2] + hap[idx * 2 + 1]) % mod;
	else hap[idx] = (mx[idx * 2] < mx[idx * 2 + 1]) ? hap[idx * 2] : hap[idx * 2 + 1];
	mx[idx] = min(mx[idx * 2], mx[idx * 2 + 1]);
}
pii find(int idx, int s, int e, int l, int r) {
	if (e < l || s > r) return { INF, 0 };
	if (l <= s && e <= r) return { mx[idx],hap[idx] };
	pii le = find(idx * 2, s, (s + e) / 2, l, r);
	pii ri = find(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
	if (le.first == ri.first) return { le.first, (le.second + ri.second) % mod };
	else return min(le, ri);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		loc.push_back(arr[i].first);
		loc.push_back(arr[i].second);
	}
	memset(mx, 0x3f, sizeof(mx));
	sort(arr, arr + n);
	sort(loc.begin(), loc.end());
	loc.erase(unique(loc.begin(), loc.end()), loc.end());
	int sz = loc.size() - 1;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(loc.begin(), loc.end(), arr[i].second) - loc.begin();
		iin.push_back(idx);
		pii cur = find(1, 0, sz, 0, idx);
		idx = lower_bound(loc.begin(), loc.end(), arr[i].first) - loc.begin();
		update(1, 0, sz, idx, (cur.second==0 ? 0 : cur.first) - arr[i].first + arr[i].second, cur.second==0 ? 1 : cur.second);
	}
	sort(iin.begin(), iin.end());
	iin.erase(unique(iin.begin(), iin.end()), iin.end());
	int mn = INF, ans = 0;
	for (int i = sz; i >=0; i--) {
		pii cc = find(1, 0, sz, i, i);
		int idx = lower_bound(iin.begin(), iin.end(), i) - iin.begin();
		if (idx == iin.size()) {
			if (mn > cc.first + loc[i]) mn = cc.first + loc[i], ans = cc.second;
			else if (mn == cc.first + loc[i]) {
				ans = (ans + cc.second) % mod;
			}
		}
	}
	printf("%d", ans);

	return 0;
}