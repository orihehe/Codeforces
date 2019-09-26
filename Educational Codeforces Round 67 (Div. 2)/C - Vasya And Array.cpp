#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define pii pair<int,int>
#define MAX 1000000000
using namespace std;

/* 🐣🐥 */
int p[1001], sz[1001];
vector<pii> vec;
int find(int a) {
	if (p[a] == -1) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	p[a] = b;
	sz[b] += sz[a];
}
int main() {
	int n, m, cm, a, b;
	scanf("%d %d", &n, &m);
	memset(p, -1, sizeof(p));
	fill(sz + 1, sz + n + 1, 1);
	while (m--) {
		scanf("%d %d %d", &cm, &a, &b);
		if (cm) {
			for (int i = a; i < b; i++) {
				merge(i, i + 1);
			}
		}
		else vec.push_back({ a,b });
	}
	for (pii v : vec) {
		int cnt = 0;
		for (int i = v.first; i < v.second; i++) {
			if (find(i) == find(i + 1)) cnt++;
		}
		if (cnt == v.second - v.first) return !printf("NO");
	}
	printf("YES\n");
	int ss = sz[find(1)];
	int srt = ss > 1 ? 0 : MAX;
	if (ss > 1) ss++;
	for (int i = 1; i <= n; i++) {
		if (ss > 1) {
			if (ss == 2) srt = 999999999;
			printf("%d ", ++srt);
			ss--;
		}
		else {
			ss = sz[find(i)];
			if (ss > 1) {
				srt = 0;
				printf("%d ", ++srt);
			}
			else {
				printf("%d ", --srt);
			}
		}
	}

	return 0;
}