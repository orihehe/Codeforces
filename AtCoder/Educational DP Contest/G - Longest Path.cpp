/*
DAG 에서의 DP문제
위상정렬을 통해 다음 정점에 현재정점+1 값과 원래 값중 큰 값을 저장
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
int deg[100001], dp[100001];
queue<int> q;
vector<int> vec[100001];
int main() {
	int n, m, a, b, ans = 0;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		deg[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int v : vec[cur]) {
			deg[v]--;
			dp[v] = max(dp[v], dp[cur] + 1);
			ans = max(dp[v], ans);
			if (deg[v] == 0) q.push(v);
		}
	}
	printf("%d", ans);

	return 0;
}