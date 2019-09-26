#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, sum = 0, arr[101];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i += 2) {
		sum += arr[i + 1] - arr[i];
	}
	printf("%d", sum);

	return 0;
}