/*
노드 수가 홀수인지 짝수인지에 따라 따로 관리해준다.
노드 수가 짝수인 경로는 그 반대로의 경로와 합하면 0이 되니 홀수인 경로의 합만 구한다.

현재 노드에는 자식노드까지의 합이 저장되도록 한다.
자식->자식은 노드수가 짝+짝, 홀+홀인 것에 + cur을 한 것이 홀수개
위로 올려줄 때는 짝수 + 본인을 하여 swap후 올려준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
ll arr[200001], ans, sum;
pll num[200001]; // 노드 수
vector<int> vec[200001];
pll dfs(int cur, int p) {
	pll o = { 0,0 }; // 홀 짝
	for (int v : vec[cur]) {
		if (v == p) continue;
		pll ret = dfs(v, cur);

		if (num[cur].second && num[v].second)
			ans = (ans + ret.second*num[cur].second%mod + o.second*num[v].second%mod
				+ ((num[v].second * num[cur].second) * arr[cur] + (num[v].second * num[cur].second) * mod) % mod) % mod;
		if (num[cur].first && num[v].first)
			ans = (ans + ret.first*num[cur].first%mod + o.first*num[v].first%mod
				+ ((num[v].first * num[cur].first) * (-arr[cur]) + (num[v].first * num[cur].first) * mod) % mod) % mod;

		o.first = (o.first + ret.first + mod) % mod;
		o.second = (o.second + ret.second + mod) % mod;

		// 노드 수
		num[cur].first += num[v].first;
		num[cur].second += num[v].second;
	}
	num[cur].second++;
	o.second = (o.second + mod + (arr[cur] * num[cur].second %mod + mod)) %mod;
	o.first = (o.first + mod - (arr[cur] * num[cur].first % mod + mod)) % mod;
	ans = (ans + o.second + mod) % mod;
	swap(num[cur].second, num[cur].first);
	swap(o.first, o.second);
	return o;
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		sum = (sum + arr[i] + mod) % mod;
	}
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 0);
	printf("%lld", (ans * 2 % mod - sum + mod) % mod);

	return 0;
}