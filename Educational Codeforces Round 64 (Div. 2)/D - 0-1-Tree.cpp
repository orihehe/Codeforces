/*
1->1, 0->0, 0->1 만 가능, 잘 세주자
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<pii> edge[2], vec[200001];
int p[2][200001], sz[2][200001], tmp;
bool visited[200001], vv[200001];
int find(int a, int w) {
	if (a == p[w][a]) return a;
	return p[w][a] = find(p[w][a], w);
}
void merge(int a, int b, int w) {
	a = find(a, w), b = find(b, w);
	if (a == b) return;
	p[w][a] = b;
	sz[w][b] += sz[w][a];
}
void dfs(int cur) {
	visited[cur] = true;
	for (pii v : vec[cur]) {
		if (v.first) {
			v.second = find(v.second, 1);
			if (!vv[v.second]) {
				tmp += sz[1][v.second] - 1;
				vv[v.second] = true;
			}
		}
		else if (!visited[v.second]) {
			dfs(v.second);
		}
	}
}
int main() {
	int n, a, b, c;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		p[0][i] = p[1][i] = i;
		sz[0][i] = sz[1][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[c].push_back({ a, b });
		vec[a].push_back({ c, b });
		vec[b].push_back({ c, a });
	}
	for (int i = 0; i < 2; i++) {
		for (pii v : edge[i]) {
			v.first = find(v.first, i), v.second = find(v.second, i);
			ans += 1LL * sz[i][v.first] * sz[i][v.second];
			merge(v.first, v.second, i);
		}
	}
	ans = ans * 2;
	for (pii v : edge[0]) {
		if (!visited[v.first]) {
			memset(vv, false, sizeof(vv));
			tmp = 0;
			dfs(v.first);
			ans += 1LL * tmp*(sz[0][find(v.first, 0)] - 1);
		}
	}
	printf("%lld", ans);

	return 0;
}