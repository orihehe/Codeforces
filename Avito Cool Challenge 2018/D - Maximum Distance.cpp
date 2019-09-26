/*
문제 이해를 못 했었는데 MooTube문제를 풀고나서 그제야 문제가 뭘 구하라는 건지 이해했다.
a에서 b로 가는 경로를 구성하는 간선들 중 가장 큰 값이 비용
a에서 b로 가는 여러 경로들의 비용 중 가장 작은 값이 거리
특별 정점들이 주어지면 그 정점에서 다른 특별정점(아무거나)로 가는 거리가 가장 먼 것을 구하는 문제이다.
자기 자신과 이어진 간선이 있고 a,b의 간선이 여러 개 있을 수 있다.

간선 배열 e에 간선정보를 넣고 오름차순 정렬 후 모든 특별정점이 이어질 때(모두 같은 집합)까지 간선을 고른다.
모두 이어졌을 때의 비용이 한 특별정점에서 다른 특별정점으로의 가장 먼 거리이다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define P pair<int,int>
using namespace std;

struct edge {
	int val, a, b;
};
bool operator < (edge& e1, edge& e2) {
	return e1.val < e2.val;
}

int q, a, b, r, n, m, etop;
edge e[200000];
int spe[100001];
int parent[100001];

int find_root(int cur) {
	if (parent[cur] == cur) return cur;
	return parent[cur] = find_root(parent[cur]);
}

bool same_set(int v1, int v2) {
	v1 = find_root(v1);
	v2 = find_root(v2);
	if (v1 == v2) return true;
	return false;
}

void merge(int v1, int v2) {
	v1 = find_root(v1);
	v2 = find_root(v2);
	if (v1 == v2) return;

	parent[v1] = v2;
}

void kruskal() {
	int lastUSA = n - 2, ans;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i < q; i++) {
		// 모든 특별 정점이 같은 부모를 가지도록
		if (same_set(spe[i], spe[i - 1])) continue;
		i--;
		merge(e[etop].a, e[etop].b);
		ans = e[etop].val;
		etop++;
	}
	for (int i = 0; i < q; i++) printf("%d ", ans);
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &spe[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &r);
		e[i] = { r,a,b };
	}
	sort(e, e + m);
	kruskal();

	return 0;
}