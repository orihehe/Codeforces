/*
각 정점에 1,2,3중 하나의 숫자를 적는데, 이어진 두 정점의 수의 합이 홀수인 그래프를 몇 개 만들 수 있는지를 구하는 문제이다.
홀수+짝수 만이 홀수가 가능하므로 dp배열을 두개 만들어 첫 정점이 홀수, 짝수인 두 경우를 나눠 계산한다.
경우의 수는 깊이가 같은 노드들 개수를 n이라고 하면 홀수일 때 2^n, 짝수일 때 1을 곱해주면 된다.
이분그래프를 사용해서 풀었다. 2^n은 n이 크면 느리니 제곱을 빠르게 하는 함수 calc를 만들어 계산했다.
calc함수에 매개변수 a를 처음에 int로 선언해서 a*a 연산에서 오버플로가 났었다. 주의해야겠다..
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