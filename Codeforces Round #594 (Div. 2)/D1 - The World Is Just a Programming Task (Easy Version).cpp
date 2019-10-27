#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
char st[501];
bool used[501];
int n, ans = 0, s = 0, e = 0;
int check() {
	memset(used, false, sizeof(used));
	vector<char> sta;
	sta.reserve(n + 1);
	for (int j = 0; j < n; j++) {
		if (st[j] == '(') sta.push_back('(');
		else {
			if (sta.empty()) continue;
			sta.pop_back();
			used[j] = true;
		}
	}
	sta.clear();

	int i, ret = 0;
	for (i = n - 1; i >= 0; i--) if (!used[i] && st[i] == ')') break;
	for (int j = i + 1; j < n; j++) {
		if (st[j] == '(') sta.push_back('(');
		else {
			if (sta.empty()) return 0;
			sta.pop_back();
			if (sta.empty()) ret++;
		}
	}
	for (int j = 0; j <= i; j++) {
		if (st[j] == '(') sta.push_back('(');
		else {
			if (sta.empty()) return 0;
			sta.pop_back();
			if (sta.empty()) ret++;
		}
	}
	if (sta.size()) return 0;
	return ret;
}
int main() {
	scanf("%d %s", &n, st);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			swap(st[i], st[j]);
			int rr = check();
			if (rr > ans) {
				ans = rr;
				s = i, e = j;
			}
			swap(st[i], st[j]);
		}
	}
	printf("%d\n%d %d", ans, s + 1, e + 1);

	return 0;
}