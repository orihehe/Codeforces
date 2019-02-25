/*
각 지점이 속한 땅의 좌표를 모두 넣고 두 좌표의 거리 완탐!
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int b[52][52];
int rgo[4] = { 0,1,0,-1 };
int cgo[4] = { 1,0,-1,0 };
vector<pii> vec, vec2;
int n, r1, c1, r2, c2, ans = 2147483640;
void dfs(int r, int c) {
	b[r][c] = -1;
	vec.push_back({ r,c });
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i], nc = c + cgo[i];
		if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
		if (b[nr][nc] == 0)
			dfs(nr, nc);
	}
}
int main() {
	scanf("%d", &n);
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &b[i][j]);
		}
	}

	dfs(r1, c1);
	vec2 = vec;
	vec.clear();
	dfs(r2, c2);
	for (pii f : vec) {
		for (pii v : vec2) {
			int x = f.first - v.first;
			int y = f.second - v.second;
			ans = min(ans, x*x + y * y);
		}
	}
	printf("%d", ans);

	return 0;
}