#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
string a, b;
string hap() {
	string ret = "";
	if (a.size() < b.size()) swap(a, b);
	int up = 0, ap, bp;
	ap = a.size() - 1;
	bp = b.size() - 1;
	while (ap >= 0 || bp >= 0) {
		if (bp == -1) {
			int tmp = a[ap] - '0' + up;
			char tt = tmp % 10 + '0';
			ret = tt + ret;
			if (tmp >= 10) {
				up = 1;
			}
			else up = 0;
			ap--;
		}
		else {
			int tmp = a[ap] - '0' + b[bp] - '0' + up;
			char tt = tmp % 10 + '0';
			ret = tt + ret;
			if (tmp >= 10)
				up = 1;
			else
				up = 0;
			bp--;
			ap--;
		}
	}
	if (up == 1) ret = '1' + ret;
	if (ret == "") return "0";
	else return ret;
}
int main() {
	int n;
	string st, ans;
	cin >> n >> st;
	ans = st;
	int srt = max(n / 2 - 3, 1), ed = min(n - 1, n / 2 + 3);
	while (srt >1 && st[srt] == '0') srt--;
	while (ed < n && st[ed] == '0') ed++;

	for (int i = srt; i <= ed; i++) {
		if (st[i] == '0') continue;
		a = b = "";
		for (int j = 0; j < i; j++) a += st[j];
		for (int j = i; j < n; j++) b += st[j];
		string tttt = hap();
		if (tttt.size() < ans.size()) ans = tttt;
		else if (tttt.size() == ans.size())
			ans = min(ans, tttt);
	}
	cout << ans;

	return 0;
}