/*
dp[현재 선택할 수][l남은 수][r남은 수]
가능한 subset을 모두 구해야 하므로 
1. 현재 수를 l에 넣는 경우
2. 현재 수를 r에 넣는 경우
3. 선택하지 않는 경우 로 나누어 준다. 
0~i~k/2까지 dp[x][k-i][i]에 대해 확인한다. 가능한 경우 2, 불가능 1
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char dp[501][501][501];
int arr[501];
int n, k, cnt;
bool use[501];
char go(int cur, int l, int r) {
	if (l <0 || r <0)return '1';
	if (cur == n) {
		if (l==0 && r==0) {
			dp[cur][l][r] = '2';
		}
		else dp[cur][l][r] ='1';
		return dp[cur][l][r];
	}
	if (dp[cur][l][r] != '0') return dp[cur][l][r];
	char tmp = go(cur + 1, l - arr[cur], r);
	tmp = max(tmp,go(cur + 1, l, r - arr[cur]));
	tmp = max(tmp, go(cur + 1, l, r));
	return dp[cur][l][r] = tmp;
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	memset(dp, '0', sizeof(dp));
	for (int i = 0; i <= k / 2 + 1; i++) {
		go(0, i, k-i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int c = 0; c <= k; c++) {
				if (dp[i][j][c]=='2') {
					use[j] = true;
					use[c] = true;
				}
			}
		}
	}
	for (int i = 0; i <= k; i++) if (use[i]) cnt++;
	printf("%d\n", cnt);
	for (int i = 0; i <= k; i++) if (use[i])printf("%d ", i);

	return 0;
}