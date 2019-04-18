#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[100001][3];
int dp[100001][3];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dp[0][0] = arr[0][0], dp[0][1] = arr[0][1], dp[0][2] = arr[0][2];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + arr[i][j];
		}
	}
	printf("%d", max({ dp[n - 1][0],dp[n - 1][1] ,dp[n - 1][2] }));

	return 0;
}