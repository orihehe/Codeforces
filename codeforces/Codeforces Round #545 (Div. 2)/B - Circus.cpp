/*
00 - a, 01 - b, 10 - c, 11 - d
a+b+c+d = n/2
c+d = nb-b+nd-d

식을 정리, a와 b를 정하여 가능 여부를 판단한다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char A[5001], B[5001];
int na, nb, nc, nd, x, y, a, b, c, d;
int main() {
	int n;
	bool suc = false;
	scanf("%d", &n);
	scanf("%s %s", A, B);
	for (int i = 0; i < n; i++) {
		if (A[i] == '0') {
			if (B[i] == '0') na++;
			else nb++;
		}
		else {
			if (B[i] == '0') nc++;
			else nd++;
		}
	}
	x = nb + nd, y = n / 2;
	for (int i = 0; i <= na; i++) {
		a = i; d = a - y + x;
		if (d < 0 || d > nd) continue;
		for (int j = 0; j <= nb; j++) {
			b = j; c = x - 2 * d - b;
			if (c >= 0 && c <= nc) {
				suc = true;
				break;
			}
		}
		if (suc) break;
	}
	if (!suc) return !printf("-1");
	for (int i = 0; i < n; i++) {
		if (a == 0) break;
		if (A[i] == '0' && B[i] == '0') {
			printf("%d ", i + 1);
			a--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (b == 0) break;
		if (A[i] == '0' && B[i] == '1') {
			printf("%d ", i + 1);
			b--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (c == 0) break;
		if (A[i] == '1' && B[i] == '0') {
			printf("%d ", i + 1);
			c--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (d == 0) break;
		if (A[i] == '1' && B[i] == '1') {
			printf("%d ", i + 1);
			d--;
		}
	}

	return 0;
}