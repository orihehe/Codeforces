#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[200001];
int main() {
	int n, idx;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == n) idx = i;
	}
	for (int i = idx; i >= 1; i--) {
		if (arr[i - 1] > arr[i]) return !printf("No");
	}
	for (int i = idx; i < n; i++) {
		if (arr[i + 1] > arr[i]) return !printf("No");
	}
	printf("Yes");

	return 0;
}