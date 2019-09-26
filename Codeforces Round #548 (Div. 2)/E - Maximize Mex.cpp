/*
potentials->club으로 간선 만들어주고,
클럽을 나가는 학생을 받아놓고, 다 나간 상태에서 뒤에서부터 추가해주며 마지막 실패 지점에서부터 이분매칭을 해준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int p[5001], A[5001];
bool visited[5001], use[5001];
vector<pii> vec[5001];
vector<int> e;
int B[5001];
bool dfs(int cur) {
	visited[cur] = true;
	for (pii v: vec[cur]) {
		if (use[v.second]) continue;
		if (B[v.first] == -1 || !visited[B[v.first]] && dfs(B[v.first])) {
			B[v.first] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	int m, n, d, x, mx = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		mx = max(mx, p[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		vec[p[i]].push_back({ --x,i });
	}
	scanf("%d", &d);
	for (int i = 0; i < d; i++) {
		scanf("%d", &x);
		e.push_back(--x);
		use[x] = true;
	}
	memset(B, -1, sizeof(B));
	int ans = 0;
	for (int i = d-1; i >= 0; i--) {
		for (; ans <= mx; ans++) {
			memset(visited, false, sizeof(visited));
			if (!dfs(ans)) break;
		}
		use[e[i]] = false;
		A[i] = ans;
	}
	for (int i = 0; i < d; i++) printf("%d\n", A[i]);

	return 0;
}