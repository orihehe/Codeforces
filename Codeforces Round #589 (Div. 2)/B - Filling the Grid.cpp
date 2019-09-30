#include <cstdio>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
int arr[1002][1002];
int main() {
	int n, m, x, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (int j = 0; j < x; j++) arr[i][j] = 1;
		arr[i][x] = 2;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		for (int j = 0; j < x; j++) {
			if (arr[j][i] == 2) return !printf("0");
			arr[j][i] = 1;
		}
		if (arr[x][i] == 1) return !printf("0");
		arr[x][i] = 2;
	}
	int ret = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 0) ans++;
	for (int i = 0; i < ans; i++) {
		ret = ret * 2 % mod;
	}
	printf("%d", ret);

	return 0;
}