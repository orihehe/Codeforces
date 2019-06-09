#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[2001];
int n, fr, ba;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + 2 * n);
	for (int i = 0; i < n; i++) fr += arr[i];
	for (int i = n; i < 2 * n; i++) ba += arr[i];
	if (fr == ba) printf("-1");
	else for (int i = 0; i < 2 * n; i++) printf("%d ", arr[i]);


	return 0;
}