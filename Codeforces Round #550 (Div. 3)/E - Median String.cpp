/*
10진수의 연속한 값들의 중앙값을 구하는 방식을 생각해본다.
그 방식대로 26진수처럼 해주기

현재 자릿수에서 올려줄 값을 올려준 뒤 왼쪽자릿수 계산에서 2로 나누어 떨어지지 않을 때는
현재 자릿수에서 26을 내려받아 계산해준다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char a[200002], b[200002];
char ans[200002];
int main() {
	int n, fr = 0, ba;
	scanf("%d", &n);
	scanf("%s %s", a, b);
	ba = b[n - 1] - 'a' + a[n - 1] - 'a';
	if (ba / 26) fr = 1;
	for (int i = n - 2; i >= 0; i--) {
		fr += b[i] - 'a' + a[i] - 'a';
		if (fr % 2) {
			ans[i + 1] = (ba % 26 / 2 + 13) % 26 + 'a';
			fr--;
		}
		else {
			ans[i + 1] = ba % 26 / 2 + 'a';
		}
		ba = fr;
		if (ba / 26) fr = 1;
		else fr = 0;
	}
	ans[0] = ba / 2 % 26 + 'a';
	printf("%s", ans);

	return 0;
}