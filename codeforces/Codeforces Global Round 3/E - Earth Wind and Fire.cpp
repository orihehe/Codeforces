#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
struct info {
	int l, r, d;
	bool operator<(const info &a) const {
		return l < a.l;
	}
};
vector<info> ans, dw, up;
int tar[300001];
info arr[300001];
int main() {
	int n, lp=0, rp=0,lz,rz;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].l);
		arr[i].d = i + 1;
	}
	for (int i = 0; i < n; i++) scanf("%d", &tar[i]);
	
	sort(arr, arr + n);
	sort(tar, tar + n);
	for (int i = 0; i < n; i++) {
		arr[i].r = tar[i] - arr[i].l;
		if (arr[i].r < 0) dw.push_back(arr[i]);
		else if (arr[i].r > 0) up.push_back(arr[i]);
	}

	lz = dw.size(), rz = up.size();
	sort(dw.begin(), dw.end());
	sort(up.begin(), up.end());
	while (lp < lz && rp < rz) {
		if (dw[lp].l - up[rp].l < min(up[rp].r, -dw[lp].r) * 2) return !printf("NO");
		if (-dw[lp].r < up[rp].r) {
			ans.push_back({ dw[lp].d, up[rp].d, -dw[lp].r });
			up[rp].r += dw[lp++].r;
		}
		else if (-dw[lp].r > up[rp].r) {
			ans.push_back({ dw[lp].d, up[rp].d, up[rp].r });
			dw[lp].r += up[rp++].r;
		}
		else {
			ans.push_back({ dw[lp].d, up[rp].d, -dw[lp].r });
			lp++, rp++;
		}
	}
	if (lp != lz || rp != rz) return !printf("NO");

	printf("YES\n");
	printf("%d\n", ans.size());
	for (info v : ans) printf("%d %d %d\n", v.r, v.l, v.d);

	return 0;
}