/*
입력되는 배열을 뒤에 하나 더 만들어준 뒤 가장 긴 연속한 1의 개수를 찾아준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[400000];
int main() {
	int n, ans = 0, mx = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		arr[i + n] = arr[i];
	}
	for (int i = 0; i < 2 * n; i++) {
		if (arr[i]) {
			mx++;
			ans = max(ans, mx);
		}
		else mx = 0;
	}
	printf("%d", ans);

	return 0;
}