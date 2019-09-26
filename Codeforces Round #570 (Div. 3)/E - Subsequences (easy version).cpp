#include <iostream>
#include <string>
#include <set>
using namespace std;

/* 🐣🐥 */
struct info {
	string a, rst;
	int dot;
	info() { dot = 0; };
	info(string x, string xx, int y) { a = x; rst = xx; dot = y; };
	bool operator <(const info &b)const {
		if (dot == b.dot) return rst < b.rst;
		return dot > b.dot;
	}
};
set<info> sss, tmp;
string st;
int main() {
	int n, k, ans = 0;
	cin >> n >> k >> st;
	sss.insert(info(st, st, 0));
	if (k == 1) return !printf("0");
	for (int i = n - 1; i >= 0; i--) {
		tmp.clear();
		for (auto iter = sss.begin(); iter != sss.end(); iter++) {
			int sz = (*iter).a.size();
			if ((*iter).a[i] != '.') {
				string irt = (*iter).a, w = "";

				int d = (*iter).dot;
				irt[i] = '.';
				for (int k = 0; k < n; k++) {
					if (irt[k] != '.') w += irt[k];
				}
				tmp.insert(info(irt, w, d + 1));
			}
		}
		for (auto iter = tmp.begin(); iter != tmp.end(); iter++) {
			sss.insert(*iter);
		}
		for (int i = sss.size(); i > k; i--) {
			sss.erase(sss.begin());
		}
	}
	if (sss.size() != k) printf("-1");
	else {
		for (auto iter = sss.begin(); iter != sss.end(); iter++) {
			ans += (*iter).dot;
		}
		printf("%d", ans);
	}

	return 0;
}