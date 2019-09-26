/*
마지막 모음과 모음 개수 별로 단어를 모아 뒤에 올 수 있는 단어 쌍을 최대로 만든다.
그리고나서 잘 조합
*/
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/* 🐣🐥 */
vector<string> vec[5][1000001];
vector<string> tt[1000001], ans, bak;
int tp = 1;
int idx[250];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, len, vv;
	char lst;
	cin >> n;
	string st;
	memset(idx, -1, sizeof(idx));
	idx['a'] = 0, idx['e'] = 1, idx['o'] = 2, idx['i'] = 3, idx['u'] = 4;
	for (int i = 0; i < n; i++) {
		cin >> st;
		len = st.size();
		vv = 0;
		for (int j = 0; j < len; j++) {
			if (idx[st[j]] != -1) {
				vv++;
				lst = st[j];
			}
		}
		vec[idx[lst]][vv].push_back(st);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j <= 1000000; j++) {
			int sz = vec[i][j].size();
			if (sz % 2) {
				tt[j].push_back(vec[i][j][sz - 1]);
				vec[i][j].pop_back();
			}
			for (string v : vec[i][j])
				bak.push_back(v);
			vec[i][j].clear();
		}
	}
	int sz = bak.size();
	if (sz <= 1) return !printf("0");
	for (int i = 0; i < sz; i += 2) {
		while (tp <= 1000000) {
			if (tt[tp].size() >= 2) break;
			tp++;
		}
		if (tp == 1000001) {
			for (int j = i; j < sz; j += 4) {
				if (j + 3 >= sz) break;
				ans.push_back(bak[j]);
				ans.push_back(bak[j + 2]);
				ans.push_back(bak[j + 1]);
				ans.push_back(bak[j + 3]);
			}
			break;
		}
		ans.push_back(tt[tp].back());
		tt[tp].pop_back();
		ans.push_back(bak[i]);
		ans.push_back(tt[tp].back());
		tt[tp].pop_back();
		ans.push_back(bak[i + 1]);
	}
	sz = ans.size();
	if (sz == 0) cout << 0;
	else {
		cout << sz / 4 << "\n";
		for (int i = 0; i < sz; i++) {
			cout << ans[i] << ((i % 2) ? "\n" : " ");
		}
	}
	return 0;
}