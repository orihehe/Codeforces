/*
xor 연산은 2^(0인 가장 왼쪽 비트 +1)-1 에서 해준다.
*/
#include <cstdio>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> ans;
int w[30], wp, cnt, p;
int main() {
	int x;
	scanf("%d", &x);
	while (x > 0) {
		if (x % 2) w[wp] = 1;
		else w[wp] = 0;
		wp++;
		x /= 2;
	}
	for (cnt; cnt < 40; cnt++) {
		if (cnt % 2) {
			p = 0;
			while (p<wp && w[p] == 1) {
				p++;
			}
			if (p == wp) break;
			w[p] = 1;
			for (--p; p >= 0; p--) w[p] = 0;
		}
		else {
			p = wp - 1;
			while (p >= 0 && w[p] == 1) {
				p--;
			}
			if (p == -1) break;
			ans.push_back(p);
			for (; p >= 0; p--) w[p] ^= 1;
		}
	}
	printf("%d\n", cnt);
	for (int v : ans) printf("%d ", v + 1);

	return 0;
}