/*
1.주어진 간선 m개 / 2.서로 다른 노드를 새로 이을 수 있는 경우 n^2개가 있다.
2번의 경우 각 노드를 가장 값이 작은 노드와 잇는 간선만을 배열에 넣는다.
그 후 크루스칼 알고리즘을 적용한다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

struct edge {
	int v1, v2;
	ll cost;
	bool operator < (const edge& e1) const { return cost < e1.cost; }
};
vector<edge> e;
int parent[200001];
ll arr[200001];
int n, m;

int find_root(int cur) {
	if (parent[cur] == cur) return cur;
	return parent[cur] = find_root(parent[cur]);
}

void merge(int v1, int v2) {
	v1 = find_root(v1);
	v2 = find_root(v2);
	parent[v1] = v2;
}
bool same_set(int v1, int v2) {
	return find_root(v1) == find_root(v2);
}

void kruskal() {
	int cnt = 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (edge &v : e) {
		if (!same_set(v.v1, v.v2)) {
			merge(v.v1, v.v2);
			ans += v.cost;
			cnt++;
		}
		if (cnt == n - 1)break;
	}

	printf("%lld", ans);
}
int main() {
	int a, b, midx;
	ll c, mv = 1000000000001;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		if (mv > arr[i]) {
			mv = arr[i];
			midx = i;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		e.push_back({ a,b,c });
	}
	for (int i = 1; i <= n; i++) {
		if (midx == i) continue;
		e.push_back({ midx,i,arr[midx] + arr[i] });
	}

	sort(e.begin(), e.end());
	kruskal();

	return 0;
}