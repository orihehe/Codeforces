/*
두 점의 맨해튼 거리는 기울기가 1,-1인 직선을 그렸을 때
y축에서의 거리의 max와 같다는 점을 이용하여 푼다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAX 2000000001
using namespace std;

/* 🐣🐥 */
int main() {
	int n, m, mx1=-MAX, mn1=MAX, mx2= -MAX, mn2=MAX, c, a, b, ans, ori=MAX, mx=0;
	scanf("%d %d %d", &n, &m, &c);
	// 모든 호텔을 포함하는 한 직사각형 범위 만들기
	while (c--) {
		scanf("%d %d", &a, &b);
		mx1 = max(mx1, a + b);
		mx2 = max(mx2, a - b);
		mn1 = min(mn1, a + b);
		mn2 = min(mn2, a - b);
	}
	scanf("%d", &c);
	for (int i = 1; i <= c; i++) {
		scanf("%d %d", &a, &b);
		mx = max({ abs(mx1 - (a + b)),abs(mn1 - (a + b)),abs(mx2 - (a - b)),abs(mn2 - (a - b)) });
		if (mx < ori) {
			ori = mx;
			ans = i;
		}
	}
	printf("%d\n%d", ori, ans);

	return 0;
}