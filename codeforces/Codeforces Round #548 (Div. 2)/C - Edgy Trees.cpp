/*
빨간 간선만으로 이동하여 도달할 수 있는 정점들을 한 그룹으로 묶어준다.
그 정점들로만 이루어진 수열의 경우의 수를 세주어 전체 경우에서 빼준다.
전제 n^k 에서 구한 그룹의 정점수^k 를 해주고, 방문하지 않은 정점으로만
이루어진 경우(1)를 추가로 빼준다.
*/
#include <cstdio>
#include <vector>
#define ll long long
#define pii pair<int,int>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
vector<ll> can; // 빨간 간선으로만 이동하는 정점의 개수 저장
vector<pii> vec[200001];
bool visited[200001];
ll ccnt;
ll mul(ll val, ll cnt) { // val^cnt
	ll ret = 1;
	while (cnt > 0) {
		if (cnt % 2 == 1) {
			ret = (ret*val) % mod;
		}
		val = (val*val) % mod;
		cnt /= 2;
	}
	return ret;
}
void dfs(int cur) {
	visited[cur] = true;
	ccnt++;
	for (pii v : vec[cur]) {
		if (!visited[v.second] && v.first == 0) {
			dfs(v.second);
		}
	}
}
int main() {
	int n, k, a, b, c;
	ll minu = 0, al;
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			ccnt = 0;
			dfs(i);
			can.push_back(ccnt);
		}
	}
	for (ll v : can) {
		minu = (minu + mul((ll)v, k)) % mod;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) minu = (minu + 1) % mod;
	}
	al = mul((ll)n, k);
	printf("%lld", (al - minu + mod) % mod);

	return 0;
}