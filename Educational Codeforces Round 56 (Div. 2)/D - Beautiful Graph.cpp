/*
�� ������ 1,2,3�� �ϳ��� ���ڸ� ���µ�, �̾��� �� ������ ���� ���� Ȧ���� �׷����� �� �� ���� �� �ִ����� ���ϴ� �����̴�.
Ȧ��+¦�� ���� Ȧ���� �����ϹǷ� dp�迭�� �ΰ� ����� ù ������ Ȧ��, ¦���� �� ��츦 ���� ����Ѵ�.
����� ���� ���̰� ���� ���� ������ n�̶�� �ϸ� Ȧ���� �� 2^n, ¦���� �� 1�� �����ָ� �ȴ�.
�̺б׷����� ����ؼ� Ǯ����. 2^n�� n�� ũ�� ������ ������ ������ �ϴ� �Լ� calc�� ����� ����ߴ�.
calc�Լ��� �Ű����� a�� ó���� int�� �����ؼ� a*a ���꿡�� �����÷ΰ� ������. �����ؾ߰ڴ�..
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long
#define mod 998244353
using namespace std;

int color[300001], dtop;
ll dp[2][300001], tmp;
vector<int> vec[300001];
ll calc(ll a, int b) {
	ll ans = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ans = (ans*a) % mod;
		}
		a = (a*a) % mod;
		b /= 2;
	}
	return ans;
}

int main() {
	int t, n, m, a, b, col, size, dt;
	ll mul = 1;
	bool fail;
	dp[0][0] = 1; dp[1][0] = 2;
	scanf("%d", &t);
	while (t--) {
		queue<int> q;
		fail = false; 
		mul = 1;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0) {
				dt = dtop = 0; 
				size = 1;
				col = 1;
				q.push(i); color[i] = 2;
				while (!q.empty()) {
					if (size == 0) {
						size = q.size();
						col = col == 1 ? 2 : 1;
						dtop++;
						tmp = calc(2, size);
						if (dtop % 2 == 1) {
							dp[0][dtop] = (dp[0][dtop - 1] * tmp) % mod;
							dp[1][dtop] = dp[1][dtop - 1];
						}
						else {
							dp[0][dtop] = dp[0][dtop - 1];
							dp[1][dtop] = (dp[1][dtop - 1] * tmp) % mod;
						}
					}
					int cur = q.front(); q.pop();
					for (int &v : vec[cur]) {
						if (color[v] == 0) {
							q.push(v);
							color[v] = col;
						}
						else if (color[v] != col) {
							fail = true;
							break;
						}
					}
					if (fail) break;
					size--;
				}
				if (dtop == dt) {
					mul = (mul * 3) % mod;
				}
				else {
					mul = (mul*(dp[0][dtop] + dp[1][dtop])) % mod;
				}
			}

			if (fail) break;
		}

		if (fail) printf("0\n");
		else {
			printf("%lld\n", mul);
		}
		for (int i = 1; i <= n; i++) {
			vec[i].clear();
			color[i] = 0;
		}
	}
	return 0;
}