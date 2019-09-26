#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<pii> vec[3], ans;
int main() {
	int n, x, y;
	double xxx, tmp;
	ll now = 0, fr = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &xxx);
		if (xxx < 0) xxx -= 1e-7;
		else xxx += 1e-7;
		x = xxx;
		fr += x;
		tmp = xxx - x;
		y = tmp * 100000;
		if (y == 0) {
			vec[2].push_back({ x,i });
		}
		else if (xxx > 0) {
			vec[0].push_back({ x,i });
			now += y;
		}
		else if (xxx < 0) {
			vec[1].push_back({ x,i });
			now += y;
		}
	}
	while (fr > 0) {
		pii cur = vec[1].back();
		vec[1].pop_back();
		ans.push_back({ cur.second,cur.first - 1 });
		fr--;
	}
	while (fr < 0) {
		pii cur = vec[0].back();
		vec[0].pop_back();
		ans.push_back({ cur.second,cur.first + 1 });
		fr++;
	}
	for (int i = 0; i < 3; i++) {
		for (pii cur : vec[i]) {
			ans.push_back({ cur.second,cur.first });
		}
	}
	sort(ans.begin(), ans.end());
	for (pii v : ans) printf("%d\n", v.second);

	return 0;
}