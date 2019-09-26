/*
BOJ 16467 문제와 같은 방식으로 푸는 문제다.
점화식이 f(n) = f(n-1) + f(n-m) 식으로 나온다.

m=3, n=6일 때를 예로 들면,
F6 = F5+F3
F5 = F4+F2
F4 = F3+F1  이고, 

이것을 행렬로 표현하면
|Fn  |   |1 0 1||Fn-1|
|Fn-1| = |1 0 0||Fn-2|
|Fn-2|	 |0 1 0||Fn-3|
*/
#include <cstdio>
#include <cstring>
#define ll long long
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
ll mat[101][101], ans[101][101];
ll n, m;
ll calc(ll b) {
	for (int i = 0; i < m; i++) {
		ans[i][i] = 1;
	}
	ll tmp[101][101];
	while (b > 0) {
		if (b % 2) {
			memset(tmp, 0, sizeof(tmp));
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					for (int k = 0; k < m; k++) {
						tmp[i][j] += ans[i][k] * mat[k][j] % mod;
					}
					tmp[i][j] %= mod;
				}
			}
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < m; k++) {
					ans[j][k] = tmp[j][k];
				}
			}
		}
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < m; k++) {
					tmp[i][j] += mat[i][k] * mat[k][j] % mod;
				}
				tmp[i][j] %= mod;
			}
		}
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				mat[j][k] = tmp[j][k];
			}
		}
		b /= 2;
	}
	return ans[0][0] % mod;
}
int main() {
	scanf("%lld %lld", &n, &m);
	mat[0][0] = mat[0][m - 1] = 1;
	for (int i = 1; i < m; i++) {
		mat[i][i - 1] = 1;
	}
	printf("%lld", calc(n));

	return 0;
}