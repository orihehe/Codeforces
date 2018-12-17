/*
문제 해석이 잘 안 돼서 시간 많이 잡아먹은 문제이다. 난 왜 영어를 못할까..
dp문제는 항상 내겐 어려운거 같다. 그래도 예전엔 못 풀었을 거 같은데 풀어서 기쁘다.
dp[k][n-k-1]에 각 n,k 가능한 벽돌 칠의 경우의 수가 저장된다. 
색 종류가 m개 있는데 첫 벽돌집합에 m가지 색 칠하기 가능, 두번째 부터 첫 벽돌집합 제외한 m-1가지 가능
*/
#include <cstdio>
#define ll long long
#define mod 998244353
using namespace std;

int n, m, k;
ll sum = 0, dp[2001][2001];
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	sum = dp[k][n - k - 1];
	for (int i = 0; i < k; i++) {
		sum = (sum*(m - 1)) % mod;
	}
	printf("%lld", (sum*m) % mod);

	return 0;
}