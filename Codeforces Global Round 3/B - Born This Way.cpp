/*
각 길이가 k 이하라면 k개를 지워 도착하지 못하도록 할 수 있다.
a배열에서 앞에서부터 하나씩 더 지워가며 k개 까지 지웠을 때
도착가능한 최소 b 위치 + 남은 지울 횟수 위치의 값의 최댓값을 저장
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int a[200001], b[200001];
int main() {
	int n, m, ta, tb, k, ans = -1;
	scanf("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	if (n <= k || m <= k) return !printf("-1");

	for (int i = 0; i <= k; i++) {
		int idx = lower_bound(b, b + m, a[i] + ta) - b;
		if (a[i] + ta > b[idx + k - i]) return !printf("-1");
		ans = max(ans, b[idx + k - i] + tb);
	}
	printf("%d", ans);

	return 0;
}