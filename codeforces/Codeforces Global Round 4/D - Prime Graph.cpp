#include <cstdio>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
bool sosu[500001];
vector<int> vec, ans;
vector<pii> edg;
bool dfs(int cur, int cnt) {
	if (cnt*vec.back() < cur || cnt * vec[0] > cur) return false;
	if (cnt == 0) return true;
	for (int v : vec) {
		if (dfs(cur - v, cnt - 1)) {
			ans.push_back(v);
			return true;
		}
	}
	return false;
}
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	int lm = n * (n - 1) / 2;
	for (int i = 2; i <= lm; i++) {
		if (sosu[i]) continue;
		if (i < n)
			vec.push_back(i);
		for (int j = 2; j*i <= lm; j++) {
			sosu[i*j] = true;
		}
	}
	for (int i = 2; i <= lm; i++) {
		if (!sosu[i]) {
			if (dfs(i * 2, n)) break;
		}
	}
	if (ans.size() == 0) return !printf("-1");
	for (int i = 0; i < n; i++) {
		if (!ans[i]) continue;
		for (int j = i + 1; j < n; j++) {
			if (!ans[i]) break;
			if (!ans[j]) continue;
			edg.push_back({ i + 1,j + 1 });
			ans[i]--, ans[j]--;
		}
	}
	if (ans[n - 2]) {
		edg.push_back({ edg[0].first,n });
		edg.push_back({ edg[0].second, n - 1 });
		printf("%d\n", edg.size() - 1);
		for (int i = 1; i < edg.size(); i++)
			printf("%d %d\n", edg[i].first, edg[i].second);
	}
	else if (ans[n - 1]) {
		edg.push_back({ edg[0].first,n });
		edg.push_back({ edg[0].second, n });
		printf("%d\n", edg.size() - 1);
		for (int i = 1; i < edg.size(); i++)
			printf("%d %d\n", edg[i].first, edg[i].second);
	}
	else {
		printf("%d\n", edg.size());
		for (pii v : edg) printf("%d %d\n", v.first, v.second);
	}

	return 0;
}