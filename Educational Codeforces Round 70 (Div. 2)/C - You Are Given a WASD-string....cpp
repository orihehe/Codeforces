#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
struct info {
	int xr, nr, xc, nc;
} arr[4];
int rgo[4] = { 1,0,-1,0 }, cgo[4] = { 0,1,0,-1 };
// 남 동 북 서
char st[200001], dir[128];
void go(int idx, int r, int c) {
	arr[idx].xr = max(arr[idx].xr, r);
	arr[idx].nr = min(arr[idx].nr, r);
	arr[idx].xc = max(arr[idx].xc, c);
	arr[idx].nc = min(arr[idx].nc, c);
}
void gg(int idx, int r, int c) {
	arr[idx].xr = arr[idx].nr = r;
	arr[idx].xc = arr[idx].nc = c;
}
int main() {
	int t, xr, nr, xc, nc;
	dir['S'] = 0, dir['W'] = 2, dir['A'] = 3, dir['D'] = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", st);
		int len = strlen(st);
		ll ans;
		memset(arr, 0, sizeof(arr));
		int r = 200000, c = 200000;
		// 0 1 2 3
		xr = nr = xc = nc = 200000;
		for (int i = 0; i < len; i++) {
			r += rgo[dir[st[i]]], c += cgo[dir[st[i]]];
			if (xr < r) {
				xr = r;
				gg(0, r, c);
			}
			else
				go(0, r, c);
			if (nr > r) {
				nr = r;
				gg(1, r, c);
			}
			else go(1, r, c);
			if (xc < c) {
				xc = c;
				gg(2, r, c);
			}
			else
				go(2, r, c);
			if (nc > c) {
				nc = c;
				gg(3, r, c);
			}
			else go(3, r, c);
		}
		ll aaa = 1LL * (xr - nr + 1) * (xc - nc + 1);
		ans = aaa;
		if (xr - nr > 1) {
			if (arr[0].nr - 1 >= nr) {
				ans = min(ans, aaa - (xc - nc + 1));
			}
			if (arr[1].xr + 1 <= xr) {
				ans = min(ans, aaa - (xc - nc + 1));
			}
		}
		if (xc - nc > 1) {
			if (arr[2].nc - 1 >= nc) {
				ans = min(ans, aaa - (xr - nr + 1));
			}if (arr[3].xc + 1 <= xc) {
				ans = min(ans, aaa - (xr - nr + 1));
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}