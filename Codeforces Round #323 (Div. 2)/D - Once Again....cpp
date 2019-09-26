/*
a의 범위는 1~300 인데 n개(100)이므로 좌표압축으로 범위를 100으로 줄여준다.

oa는 [수열 개수 (1,2,4,8,...2^k)][i이상][j이하] 일때의 최대 길이
주어지는 수열에서 [i이상][j이하]의 가장 긴 길이를 oa[0]배열에 저장해둔다.

방법은 idx이전의 값들중 최댓값에 arr[i](idx)를 붙인다고 생각하여
j이상 -> idx이하의 값, k이하 -> j이상 idx이하의 값들 중 가장 큰값을 찾아준다.
그리고나서 oa[x][i][j] = oa[x-1][i][k] + oa[x-1][k][j] 의 최댓값으로 저장한다.

이제 t개의 수열을 사용하는데 t를 이진수로 나타냈을 때 켜진 비트를 선택해주면 된다.
켜진 비트를 조합해야하는데 범위마다 최댓값이 들어가있으니 그것의 사용 순서는 상관이 없다.
go함수에서 작은 길이부터 차례로 선택하며 범위를 정해준다.
범위를 촘촘히 사용하니 이전의 끝값~n-1까지를 모두 봐준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int arr[101], nm[101], oa[24][101][101];
int wprhq[24], dp[24][101];
bool use[24];
int n, t, x = 1;
int go(int cur, int s) {
	if (cur == 24) return 0;
	if (dp[cur][s] != -1) return dp[cur][s];
	int ret = 0;
	if (use[cur]) {
		for (int j = s; j < n; j++) {
			ret = max(ret, oa[cur][s][j] + go(cur + 1, j));
		}
	}
	else ret = go(cur + 1, s);
	return dp[cur][s] = ret;
}
int main() {
	scanf("%d %d", &n, &t);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		nm[i] = arr[i];
	}
	// 2^i꼴 배열에 채우고
	for (int i = 0; i < 24; i++) {
		wprhq[i] = x;
		x *= 2;
	}
	for (int i = 23; i >= 0; i--) {
		if (t >= wprhq[i]) {
			use[i] = true;
			t -= wprhq[i];
		}
	}
	sort(nm, nm + n);
	// lis
	for (int i = 0; i < n; i++) {
		// 좌표압축
		int idx = lower_bound(nm, nm + n, arr[i]) - nm;
		for (int j = idx; j >= 0; j--) {
			for (int k = idx; k >= j; k--) {
				oa[0][j][idx] = max(oa[0][j][idx], oa[0][j][k] + 1);
			}
		}
	}
	for (int u = 1; u < 24; u++) {
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				for (int k = i; k <= j; k++) {
					oa[u][i][j] = max(oa[u][i][j],
						oa[u - 1][i][k] + oa[u - 1][k][j]);
				}
			}
		}
	}
	printf("%d",go(0, 0));

	return 0;
}