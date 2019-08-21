#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[21][21];
ll ans[20][20];
char st[2000001];
int num[100];
void fill(int n, int m) {
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			arr[i][j] = (n*i + m * j) % 10;
		}
	}
}
ll solve() {
	ll ret = 0;
	for (int k = 0; k < 100; k++) {
		if (!num[k]) continue;
		ll tmp = 0;
		int r, c, mx = -1;
		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 20; j++) {
				if (arr[i][j] == k % 10 && mx < i + j) {
					mx = i + j;
					r = i, c = j;
				}
			}
		}
		if (mx == -1) return -1;
		tmp = mx;
		mx = -1;

		for (int i = 0; i <= r; i++) {
			for (int j = 0; j <= c; j++) {
				if (i == r && j == c) continue;
				if (arr[i][j] == k / 10 && mx < i + j) {
					mx = i + j;
				}
			}
		}
		if (mx == -1) return -1;
		tmp -= mx;
		ret += tmp * num[k];
	}
	return ret;
}
int main() {
	scanf("%s", st);
	int len = strlen(st);
	for (int i = 1; i < len; i++) {
		num[(st[i - 1] - '0') * 10 + st[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fill(i, j);
			ans[i][j] = solve();
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%lld ", ans[i][j] != -1 ? ans[i][j] - len + 1 : -1);
		}
		printf("\n");
	}

	return 0;
}