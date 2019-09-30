/*
1번 정점과 이어진 정점들을 1번 그룹으로 만든다.
그 후 남은 정점들 만으로 이분그래프를 만들 수 있는지 확인하고
3개의 그룹이 생겼는지 확인, 다른 그룹으로의 간선이 모두 있는지 확인해준다.
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
vector<int> vec[300001];
int ans[300001];
int cnt[300001][4];
queue<int> q;
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int v : vec[1]) {
		ans[v] = 1;
	}
	for (int i = 1; i <= n; i++) ans[i] = !ans[i];
	for (int i = 1; i <= n; i++) {
		if (!ans[i]) {
			q.push(i);
			ans[i] = 2;
			break;
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int v : vec[cur]) {
			if (ans[v] == ans[cur]) return !printf("-1");
			if (ans[v]) continue;
			if (ans[cur] == 2) {
				ans[v] = 3;
			}
			else ans[v] = 2;
			q.push(v);
		}
	}
	bool suc = false;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 3) suc = true;
		if (ans[i] == 0) return !printf("-1");
	}
	if (!suc) return !printf("-1");

	int s[4];
	for (int i = 1; i <= n; i++) {
		s[ans[i]] = vec[i].size();
	}
	for (int i = 1; i <= n; i++) {
		if (s[ans[i]] != vec[i].size()) return !printf("-1");
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}
