/*
연속한 L, R별로 간선을 만들어주어 위상정렬로 1에서부터 증가시켜주면 된다.
그 후 같은 값을 가지는 부분만 따로 처리!
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
int arr[1001], deg[1001], mm;
vector<int> vec[1001];
queue<int> q;
int n, lp;
char st[1001], lc;
void dfs(int cur) {
	deg[cur] = 0;
	mm = max(arr[cur], mm);
	if (st[cur] == '=') dfs(cur + 1);
	arr[cur] = mm;
}
int main() {
	scanf("%d %s", &n, st);
	for (int i = 0; i < n-1; i++) {
		if (st[i] == 'L') {
			if (st[i - 1] == '=' && lc == 'L') {
				vec[i + 1].push_back(lp);
				deg[lp]++;
			}
			else {
				vec[i + 1].push_back(i);
				deg[i]++;
			}
			lc = 'L';
			lp = i+1;
		}
		else if (st[i] == 'R') {
			if (st[i - 1] == '=' && lc == 'R') {
				vec[lp].push_back(i+1);
				deg[i+1]++;
			}
			else {
				vec[i].push_back(i + 1);
				deg[i + 1]++;
			}
			lc = 'R';
			lp = i+1;
		}
	}
	for (int i = 0; i < n; i++)
		if (!deg[i]) {
			q.push(i);
			arr[i] = 1;
		}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int v : vec[cur]) {
			deg[v]--;
			arr[v] = arr[cur] + 1;
			if (deg[v] == 0) q.push(v);
		}
	}
	for (int i = 0; i < n-1; i++) {
		if (st[i]=='=') {
			mm = 0;
			dfs(i);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", max(1, arr[i]));
	}

	return 0;
}