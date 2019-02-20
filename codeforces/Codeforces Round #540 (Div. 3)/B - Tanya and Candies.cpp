/*
홀수, 짝수를 따로 부분합
아빠를 드리는 사탕 i와 사탕의 개수 n의 경우에 따라 따로 생각해준다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[200005], fr, ba, cnt;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n + 1; i++) {
		scanf("%lld", &arr[i]);
		arr[i] += arr[i - 2];
	}
	for (int i = 2; i <= n + 1; i++) {
		fr = ba = 0; //fr홀수 ba짝
		if (i % 2 == 0) {
			fr = arr[i - 2];
			ba = arr[i - 1];
			if ((n + 1) % 2 == 0) {
				ba += arr[n + 1] - arr[i];
				fr += arr[n] - arr[i - 1];
			}
			else {
				ba += arr[n] - arr[i];
				fr += arr[n + 1] - arr[i - 1];
			}
		}
		else {
			fr = arr[i - 1];
			ba = arr[i - 2];
			if ((n + 1) % 2 == 0) {
				ba += arr[n + 1] - arr[i - 1];
				fr += arr[n] - arr[i];
			}
			else {
				ba += arr[n] - arr[i - 1];
				fr += arr[n + 1] - arr[i];
			}
		}
		if (fr == ba) cnt++;
	}
	printf("%lld", cnt);

	return 0;
}