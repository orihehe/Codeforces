#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[200001];
int p[200001];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	int q, n, x;
	ll ans = 0;
	scanf("%d", &q);
	while (q--) {
		ans = 0;
		scanf("%d", &n);
		fill(arr + 1, arr + n + 1, 0);

		p[n] = n;
		for (int i = 0; i < n; i++) {
			p[i] = i;
			scanf("%d", &x);
			arr[x]++;
		}
		for (int i = 1; i <= n; i++) {
			int tmp = find(arr[i]);
			if (tmp) {
				ans += tmp;
				merge(tmp - 1, tmp);
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}