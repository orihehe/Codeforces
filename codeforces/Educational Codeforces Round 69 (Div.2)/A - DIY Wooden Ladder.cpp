#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[100001];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		sort(arr, arr + n);
		printf("%d\n", min(n - 2, arr[n - 2] - 1));
	}

	return 0;
}