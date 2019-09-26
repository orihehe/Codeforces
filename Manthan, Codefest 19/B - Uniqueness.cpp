#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int arr[2001];
map<int, int> mp;
set<int> sss;
vector<pii> vec;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		mp[arr[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (mp[arr[i]] >= 2) vec.push_back({ arr[i],i });
	}
	if (vec.size() == 0) return !printf("0");
	int ans, p;
	int sz = vec.size();
	for (int i = 0; i < sz; i++) {
		if (sss.find(vec[i].first) != sss.end()) {
			ans = vec[sz - 1].second - vec[i].second + 1;
			p = i - 1;
			break;
		}
		sss.insert(vec[i].first);
	}
	for (int i = sz - 1; i >= 0; i--) {
		while (p >= 0 && !sss.empty() && sss.find(vec[i].first) != sss.end()) {
			sss.erase(vec[p--].first);
		}
		if (sss.find(vec[i].first) != sss.end()) break;
		ans = min(ans, vec[i - 1].second - vec[p + 1].second + 1);
		sss.insert(vec[i].first);
	}
	printf("%d", ans);

	return 0;
}