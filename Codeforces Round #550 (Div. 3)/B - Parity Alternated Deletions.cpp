/*
홀수 짝수 나누어 배열에 저장한다.
저장 후 더 많은 원소를 가진 배열에서 차이만큼 작은 값을 더해 출력
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int ev[2001], od[2001], ep, op, pp, ans;
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x % 2) {
			od[op++] = x;
		}
		else ev[ep++] = x;
	}
	sort(od, od + op);
	sort(ev, ev + ep);
	if (ep < op) {
		for (int i = 0; i < op - ep - 1; i++) {
			ans += od[i];
		}
	}
	else {
		for (int i = 0; i < ep - op - 1; i++) {
			ans += ev[i];
		}
	}
	printf("%d", ans);

	return 0;
}