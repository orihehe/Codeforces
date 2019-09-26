/*
s, t 기준 오름차순 sort 후 coin 배열에 i번째에 얻을 수 있는 최대 w, w가 같다면 최대d 를 넣는다.
그리고나서 go에서 cnt(방해 횟수)가 남아있다면 방해했을 경우와 안 했을 경우의 최솟값을,
cnt가 0이라면 안 했을 경우를 탐색해준다. dp배열에 메모이제이션하여 이미 구한 값은 그냥 리턴.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long
#define P pair<ll,ll>
using namespace std;

P coin[100001];
ll dp[201][100001];
int n, m, k;
struct ev {
	ll s, t, d, w;
	bool operator < (const ev &a) const {
		if (w == a.w) return d < a.d;
		return w < a.w;
	}
};
bool cmp(ev &a, ev&b) {
	if (a.s == b.s) return a.t < b.t;
	return a.s < b.s;
}
ev arr[100001];
priority_queue<ev> pq;
int ap;
ll go(ll cur, ll cnt) { 
	if (cur > n) {
		return 0;
	}
	if (dp[cnt][cur] != -1) return dp[cnt][cur];
	if (coin[cur].second == 0) return dp[cnt][cur] = go(cur + 1, cnt);
	if (cnt > 0) {
		return dp[cnt][cur] = min(go(cur + 1, cnt - 1),
			go(coin[cur].second + 1, cnt) + coin[cur].first);
	}
	return dp[cnt][cur] = go(coin[cur].second + 1, cnt) + coin[cur].first;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%lld %lld %lld %lld", &arr[i].s, &arr[i].t, &arr[i].d, &arr[i].w);
	}
	sort(arr, arr + k, cmp);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		while (ap<k && arr[ap].s == i) {
			pq.push(arr[ap++]);
		}
		while (!pq.empty() && pq.top().t < i) pq.pop();
		if (!pq.empty()) {
			coin[i] = { pq.top().w,pq.top().d };
		}
	}
	printf("%lld", go(1, m));

	return 0;
}