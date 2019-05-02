/*
최솟값, 최댓값은 1번 이상, 중간 값들은 2번 이상 등장하는 연속한 수의 최대 개수를 구한다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[200002];
int main() {
	int n, x, mx = 0, tmp = 0, l, r, last=200002;
	bool c = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[x]++;
		last = min(x,last);
	}
	for (int i = last; i <= 200001; i++) {
		if (!c && arr[i]) { // 시작점
			c = true;
			last = i;
			tmp += arr[i];
		}
		else if (arr[i]) {
			tmp += arr[i];
			if (mx < tmp) {
				mx = tmp;
				l = last, r = i;
			}
			if (arr[i] == 1) {
				last = i;
				tmp = arr[i];
			}
		}
		else {
			if (mx < tmp) {
				mx = tmp;
				l = last, r = i-1;
			}
			tmp = 0;
			c = false;
		}
	}
	printf("%d\n", mx);
	for (int i = l; i <= r; i++) {
		arr[i]--;
		printf("%d ", i);
	}
	for (int i = r; i >= l; i--) {
		if(arr[i]>0)
			while (arr[i]--) printf("%d ", i);
	}

	return 0;
}