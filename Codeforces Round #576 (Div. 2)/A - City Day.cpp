#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[100001];
int main() {
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		bool suc = true;
		for (int j = max(0, i - x); j <= min(i + y, n - 1); j++) {
			if (arr[j] < arr[i]) suc = false;
		}
		if (suc)return !printf("%d", i + 1);
	}
	return 0;
}