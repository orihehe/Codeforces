/*
이분그래프로 만들어서 풀면 된다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii ed[200001];
int col[200001];
bool suc = true;
vector<int> vec[200001];
void dfs(int cur, int c) {
	col[cur] = c + 1;
	for (int nx : vec[cur]) {
		if (col[nx] == c + 1) suc = false;
		if (col[nx] == 0) {
			dfs(nx, (c + 1) % 2);
		}
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &ed[i].first, &ed[i].second);
		vec[ed[i].first].push_back(ed[i].second);
		vec[ed[i].second].push_back(ed[i].first);
	}
	dfs(1, 0);
	if (!suc) printf("NO");
	else {
		printf("YES\n");
		for (int i = 0; i < m; i++) {
			if (col[ed[i].first] == 1) {
				printf("1");
			}
			else printf("0");
		}
	}

	return 0;
}