/*
1꼭짓점과 3~n-1 꼭짓점들을 이어준 값이 최소이다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int main() {
	int n;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 2; i < n; i++) {
		ans += i * (i + 1);
	}
	printf("%lld", ans);

	return 0;
}