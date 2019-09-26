/*
각 수가 두번보다 많이 등장하지 않는다면 가능
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[200001], cnt[200001];
int inc[200001], dec[200001], ip, dp;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
		if (cnt[arr[i]] > 2) return !printf("NO");
	}
	sort(arr, arr + n);
	arr[n] = 200001;
	for (int i = 0; i < n; i++) {
		inc[ip++] = arr[i];
		if (arr[i] == arr[i + 1]) {
			dec[dp++] = arr[i];
			i++;
		}
	}
	printf("YES\n");
	printf("%d\n", ip);
	for (int i = 0; i < ip; i++) {
		printf("%d ", inc[i]);
	}
	printf("\n%d\n", dp);
	for (int i = dp - 1; i >= 0; i--) printf("%d ", dec[i]);

	return 0;
}