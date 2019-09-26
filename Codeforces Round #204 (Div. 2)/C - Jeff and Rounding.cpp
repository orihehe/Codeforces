/*
소숫점 아래 수들만 배열에 저장, 0인 경우 개수를 세준다.
a는 앞, b는 뒤의 연속한 합, a를 올림, b를 내림의 경우로 생각한다.
0을 a의 앞, b의 뒤에 붙이는 경우를 고려하여 모든 경우 중 최솟값을 찾아 출력
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[4001], ap;
int main() {
	int n, ans=20000000, cnt0 = 0, a = 0, b = 0, ptr, sum = 0;
	double x;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%lf", &x);
		x += 1e-8;
		if ((int)(x * 1000) % 1000 == 0) cnt0++;
		else {
			arr[ap++] = (int)(x * 1000) % 1000;
			sum += arr[ap - 1];
		}
	}
	sort(arr, arr + ap);
	ptr = (ap+1) / 2-(cnt0+1) / 2;
	ptr = ptr < 0 ? 0 : ptr;
	for (int i = 0; i < ptr; i++) a += arr[i];
	b = sum - a;
	ans = min(ans, abs(ptr * 1000 - a - b));
	ans = min(ans, abs((ap - ptr) * 1000 - a - b));
	for (int i = ptr; i < ap - ptr; i++) {
		a += arr[i];
		b -= arr[i];
		ans = min(ans, abs((i+1) * 1000 - a - b));
	}

	printf("%d.%03d", ans / 1000, ans % 1000);

	return 0;
}