/*
현재 역 기준 사탕 배달 하는데의 최소 cost는
(사탕수-1)*역의 수(n) + 가장 가까운 역 이다.
각 역에서 시작했을 때 다른 역까지 가는 거리 + 그 역의 사탕이 마지막으로 배달했을 때 cost 에서
가장 큰 값이 최소 cost가 된다.
*/
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[5001]; // 앞 cnt, 뒤 가까운 역
int n, m, a, b, k, mx, cnt, tc;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		arr[i].second = n;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		k = b - a;
		if (k < 0) k += n;
		arr[a].second = min(arr[a].second, k);
		arr[a].first++;
	}
	for (int i = 1; i <= n; i++) {
		cnt = tc = 0;
		for (int j = i; j <= n; j++) {
			tc++;
			if (arr[j].first == 0) {
				continue;
			}
			cnt = max(cnt, (arr[j].first - 1)*n + arr[j].second + tc);
		}
		for (int j = 1; j < i; j++) {
			tc++;
			if (arr[j].first == 0) {
				continue;
			}
			cnt = max(cnt, (arr[j].first - 1)*n + arr[j].second + tc);
		}
		printf("%d ", cnt - 1);
	}

	return 0;
}