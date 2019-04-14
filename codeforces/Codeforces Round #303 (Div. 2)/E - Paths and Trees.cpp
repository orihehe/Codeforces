/*
다익스트라를 돌리면서 현재 정점까지의 기록된 거리와 같을 시 직전의 마지막 간선과
현재 간선을 비교하여 작은 값을 가지는 것을 선택한다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define MAX 300000000000001
using namespace std;

/* 🐣🐥 */
vector<pii> vec[300001];
vector<int> ans;
ll dist[300001], aaa;
int srt, p[300001];
bool visited[300001];
map<pii, pii> mp;
priority_queue<pli, vector<pli>, greater<pli>> pq;
void djk() {
	dist[srt] = 0;
	pq.push({ 0,srt });
	while (!pq.empty()) {
		pli cur = pq.top();
		pq.pop();
		if (cur.first > dist[cur.second]) continue;
		for (pli v : vec[cur.second]) {
			ll tmp = cur.first + v.first;
			if (tmp < dist[v.second]) {
				dist[v.second] = tmp;
				p[v.second] = cur.second;
				pq.push({ tmp,v.second });
			}
			else if (tmp == dist[v.second] && v.first < mp[{v.second, p[v.second]}].second) {
				dist[v.second] = tmp;
				p[v.second] = cur.second;
			}
		}
	}
}
void dfs(int cur) {
	visited[cur] = true;
	ans.push_back(mp[{cur, p[cur]}].first);
	aaa += mp[{cur, p[cur]}].second;
	if (!visited[p[cur]]) dfs(p[cur]);
}
int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	fill(dist, dist + n + 1, MAX);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		mp[{a, b}] = { i + 1, c };
		mp[{b, a}] = { i + 1, c };
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	scanf("%d", &srt);
	djk();
	visited[srt] = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) dfs(i);
	}
	printf("%lld\n", aaa);
	for (int v : ans) printf("%d ", v);

	return 0;
}