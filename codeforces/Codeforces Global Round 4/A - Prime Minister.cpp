#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[101];
bool ans[101];
int main() {
	int n, as = 0, sum = 0, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	ans[0] = true;
	as = arr[0];
	cnt = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] <= arr[0] / 2) {
			ans[i] = true;
			cnt++;
			as += arr[i];
		}
	}
	if (as <= sum / 2) printf("0");
	else {
		printf("%d\n", cnt);
		for (int i = 0; i < n; i++) {
			if (ans[i]) printf("%d ", i + 1);
		}
	}

	return 0;
}