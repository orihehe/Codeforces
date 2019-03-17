/*
SWEA 1238. Contact

bfs로 마지막 깊이에서의 최댓값을 찾아주면 된다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
queue<int> q;
bool visited[101];
vector<int> vec[101];
int main() {
	//freopen("input.txt", "r", stdin);
	int t = 1, n, m, a, b, ans, s, last;
	while(~scanf("%d %d", &n, &m)) {
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n / 2; i++) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
		}
		ans = 0;
		q.push(m);
		s = 1;
		while (!q.empty()) {
			if (s == 0) {
				s = q.size();
				last = ans;
				ans = 0;
			}
			int cur = q.front();
			q.pop();
			for (int v : vec[cur]) {
				if (!visited[v]) {
					ans = max(ans, v);
					q.push(v);
					visited[v] = true;
				}
			}
			s--;
		}
		printf("#%d %d\n", t++, last);
		for (int i = 1; i <= 100; i++) vec[i].clear();
	}

	return 0;
}