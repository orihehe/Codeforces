/*
등차수열의 합공식으로 현재 수가 x일 때 나타낼 수 있는 최솟값을 구한다.
이분탐색으로 현재 위치의 최댓값을 찾는다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[100001];
int main() {
	int n, k, l, r, cur;
	ll sum = 0, tmp;
	scanf("%d %d", &n, &k);

	l = 0, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (1LL * (mid + mid + k - 1)*k / 2 > n) {
			r = mid - 1;
		}
		else {
			arr[0] = mid;
			l = mid + 1;
		}
	}
	if (!arr[0]) return !printf("NO");

	sum = arr[0];
	for (int i = 1; i < k; i++) {
		l = arr[i - 1] + 1, r = arr[i - 1] * 2;
		while (l <= r) {
			int mid = (l + r) / 2;
			tmp = 1LL * (2 * mid + k - i - 1) * (k - i) / 2;
			if (tmp > 1LL * n - sum) {
				r = mid - 1;
			}
			else {
				arr[i] = mid;
				l = mid + 1;
			}
		}
		if (!arr[i])return !printf("NO");
		sum += arr[i]; // 현재까지 확정한 합
	}
	if (sum != n) return !printf("NO");
	printf("YES\n");
	for (int i = 0; i < k; i++) printf("%d ", arr[i]);

	return 0;
}