/*
a b c를 고르는데
a를 하나 정하고나면 b의 가장 큰 약수는 b/2이므로 나올 수 있는 b는 한 가지 뿐이다.
그리고나서 a와 b의 약수가 아닌 가장 큰 수를 c로 선택.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[200001];
int main() {
	int q, n, a, b, c, ans;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n);
		n = unique(arr, arr + n) - arr;
		ans = a = b = c = 0;
		for (int i = n - 1; i >= 0; i--) {
			a = arr[i];
			for (int j = i - 1; j >= 0; j--) {
				if (a % arr[j] != 0) {
					b = arr[j];
					break;
				}
			}
			if (b == 0) {
				ans = max(ans, a);
				continue;
			}
			for (int j = i - 1; j >= 0; j--) {
				if (a%arr[j] != 0 && b%arr[j] != 0) {
					c = arr[j];
					break;
				}
			}
			if (c != 0)
				ans = max(ans, a + b + c);
			else ans = max(ans, a + b);
		}
		printf("%d\n", ans);
	}

	return 0;
}