#include <cstdio>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int A[51][51];
int b[51][51];
vector<pii> ans;
bool allo(int r, int c) {
	for (int i = r; i < r + 2; i++)
		for (int j = c; j < c + 2; j++)
			if (!A[i][j]) return false;
	return true;
}
void pls(int r, int c, int val) {
	for (int i = r; i < r + 2; i++)
		for (int j = c; j < c + 2; j++)
			b[i][j] += val;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++) {
			if (allo(i, j)) {
				pls(i, j, 1);
				ans.push_back({ i,j });
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (A[i][j] && !b[i][j]) return !printf("-1");
		}
	printf("%d\n", ans.size());
	for (pii v : ans) printf("%d %d\n", v.first + 1, v.second + 1);

	return 0;
}