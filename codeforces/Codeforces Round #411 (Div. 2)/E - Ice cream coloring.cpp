/*
현재 노드의 아이스크림들의 이미 색칠된 색 정보를 구하고,
남은 색을 앞에서부터 부여해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> arr[300001], vec[300001], no;
int cl[300001], cc[300001], cp, ans;
bool visited[300001];
void dfs(int cur) {
	no.clear();
	cp = 1;
	visited[cur] = true;
	for (int v : arr[cur]) {
		if (cl[v] == 0) no.push_back(v);
		else cc[cl[v]] = cur;
	}
	for (int v : no) {
		while (cc[cp] == cur) cp++;
		cl[v] = cp; cc[cp] = cur;
	}
	ans = max(cp, ans);
	for (int v : vec[cur]) if (!visited[v]) dfs(v);
}
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		while (a--) {
			scanf("%d", &b);
			arr[i].push_back(b);
		}
	}
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1);
	printf("%d\n", ans);
	for (int i = 1; i <= m; i++) printf("%d ", cl[i] == 0 ? 1 : cl[i]);

	return 0;
}