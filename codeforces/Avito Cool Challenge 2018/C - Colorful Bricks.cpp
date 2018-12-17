/*
���� �ؼ��� �� �� �ż� �ð� ���� ��Ƹ��� �����̴�. �� �� ��� ���ұ�..
dp������ �׻� ���� ������ ����. �׷��� ������ �� Ǯ���� �� ������ Ǯ� ��ڴ�.
dp[k][n-k-1]�� �� n,k ������ ���� ĥ�� ����� ���� ����ȴ�. 
�� ������ m�� �ִµ� ù �������տ� m���� �� ĥ�ϱ� ����, �ι�° ���� ù �������� ������ m-1���� ����
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