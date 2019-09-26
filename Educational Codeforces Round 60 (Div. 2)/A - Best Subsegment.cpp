/*
부분합에서 평균이 가장 큰 것들중 가장 긴 길이를 출력하는 문제
가장 큰 숫자가 연속해서 나오는 가장 긴 길이를 구해준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[100001], ap;
int main() {
	int n, x, mV = -1, cnt = 0, last = -1, ans = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x != last) {
			cnt = 0;
		}
		if (x > mV) {
			mV = x;
			cnt = 1;
			ans = 1;
		}
		else if (x == mV) {
			cnt++;
			ans = max(ans, cnt);
		}
		last = x;
	}
	printf("%d", ans);

	return 0;
}