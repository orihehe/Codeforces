#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool yu[100];

bool isSame(string a, string b) {
	int prolen = a.size();
	if (prolen > b.size()) return false;
	for (int j = 0; j < prolen; j++) {
		if (a[j] != b[j]) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("A-small-attempt4.in", "r", stdin);
	int t,n,p; //p가 금지 개수
	long long cnt;
	vector<string> st;
	cin >> t;
	for(int ca=1;ca<=t;ca++) {
		st.clear();
		cnt = 0;
		cin >> n >> p;
		st.resize(p);
		for (int i = 0; i < p; i++) {
			cin >> st[i];
			yu[i] = true;
		}
		sort(st.begin(), st.end());
		for (int i = 0; i < p; i++) {
			int prolen = st[i].size();
			if (yu[i]) {
				for (int k = i+1; k < p; k++) {// 뒤애들
					if (isSame(st[i],st[k])) {
						yu[k] = false;
					}
				}
			}
		}
		for (int i = 0; i < p; i++) {
			if (yu[i]) {
				cnt += pow(2, n - st[i].size());
			}
		}
		printf("Case #%d: %lld\n", ca, (long long)pow(2, n) - cnt);
		
	}

	return 0;
}