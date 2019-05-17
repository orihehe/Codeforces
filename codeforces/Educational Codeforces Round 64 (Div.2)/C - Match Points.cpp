#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[200000];
int main() {
	int n, z, mid, ans = 0;
	scanf("%d %d", &n, &z);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	mid = n / 2;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) break;
		while (arr[i] + z > arr[mid] && mid < n) mid++;
		while (arr[mid] == -1 && mid < n) mid++;
		if (mid < n) {
			ans++;
			arr[mid++] = -1;
		}
	}
	printf("%d", ans);

	return 0;
}