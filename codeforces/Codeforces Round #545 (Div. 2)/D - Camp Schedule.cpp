/*
접두사와 접미사가 같은 최대 길이를 구하여 그 접두사 외의 뒷 부분만 붙여준다.
*/
#include <cstdio>
#include <cstring>
#define ll long long
#define mod1 1000000009
#define mod2 1000000021
using namespace std;

/* 🐣🐥 */
char st[500002], t[500002], tmp[500002];
ll vec1[500001], vec2[500001];
ll wprhq[2][500001], x = 1, y = 1;
int a, b, c, d;
int main() {
	ll x = 1, y = 1, sum = 0;
	scanf("%s %s", st + 1, t + 1);
	int slen = strlen(st + 1);
	int n = strlen(t + 1), mx = 0;

	for (int i = 1; i <= slen; i++) {
		if (st[i] == '1') a++;
		else b++;
	}
	for (int i = 1; i <= n; i++) {
		if (t[i] == '1') c++;
		else d++;
	}

	for (int i = 0; i < n; i++) {
		wprhq[0][i] = x;
		wprhq[1][i] = y;
		x = x * 256 % mod1;
		y = y * 256 % mod2;
	}
	for (int i = 1; i <= n; i++) {
		vec1[i] = (vec1[i - 1] + t[i] * wprhq[0][n - i] % mod1) % mod1;
		vec2[i] = (vec2[i - 1] + t[i] * wprhq[1][n - i] % mod2) % mod2;
	}
	for (int i = 1; i < n; i++) { // 길이
		ll t1 = (vec1[n] - vec1[n - i] + mod1) % mod1 * wprhq[0][n - i] % mod1;
		ll t2 = (vec2[n] - vec2[n - i] + mod2) % mod2 * wprhq[1][n - i] % mod2;
		if (t1 == vec1[i] && t2 == vec2[i]) mx = i;
	}
	if (a >= c && b >= d) {
		printf("%s", t + 1);
		a -= c, b -= d;
		for (int i = 1; i <= mx; i++) {
			if (t[i] == '1') c--;
			else d--;
		}
		strcpy(tmp, t + mx + 1);
		while (a >= c && b >= d) {
			printf("%s", tmp);
			a -= c, b -= d;
		}
		while (a--) printf("1");
		while (b--) printf("0");
	}
	else {
		printf("%s", st + 1);
	}

	return 0;
}