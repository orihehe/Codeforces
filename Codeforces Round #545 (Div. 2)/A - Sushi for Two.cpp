#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[100001];
int main() {
	int n, x, ap = 0, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (arr[ap].first == x) arr[ap].second++;
		else arr[++ap] = { x,1 };
	}
	for (int i = 1; i < ap; i++) {
		ans = max(ans, min(arr[i].second, arr[i + 1].second));
	}
	printf("%d", 2 * ans);

	return 0;
}