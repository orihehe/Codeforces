#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
int arr[400001], cnt[400001];
vector<int> vec;
int main() {
	int n, m, d, last = 1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		vec.push_back(arr[i]);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 1; i < 31; i++) {
		if (n*i > 8 * m)break;
		last *= 2;
	}
	int sz = vec.size();
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
		cnt[idx + 1]++;
	}
	int ans = INF;
	for (int i = 1; i <= sz; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = last; i <= sz; i++) {
		ans = min(ans, cnt[i - last] + cnt[sz] - cnt[i]);
	}

	printf("%d", ans == INF ? 0 : ans);

	return 0;
}