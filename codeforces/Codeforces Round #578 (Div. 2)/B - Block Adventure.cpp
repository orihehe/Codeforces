#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[101];
int main() {
	int t, n, m, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		bool suc = true;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] + k >= arr[i + 1]) {
				m += arr[i] - max(0, arr[i + 1] - k);
			}
			else {
				if (m < arr[i + 1] - k - arr[i]) {
					suc = false;
					break;
				}
				else {
					m -= arr[i + 1] - k - arr[i];
				}
			}
		}
		if (suc) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}