/*
책을 그만 읽을 시점은 현재까지 나온 최댓값이 i와 같을 때이다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[10001];
int main() {
	int n, mx = 0, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		mx = max({ mx, arr[i] });
		if (mx == i) cnt++;
	}
	printf("%d", cnt);

	return 0;
}