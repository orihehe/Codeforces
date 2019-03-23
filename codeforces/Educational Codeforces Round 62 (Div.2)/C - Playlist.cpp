/*
뷰티를 기준으로 내림차순 정렬 후 큰 뷰티부터 봐준다.
뷰티를 정해두고 그것보다 큰 뷰티를 가진 길이는 모두 선택할 수 있다.
선택할 수 있는 값들 중 큰 k개를 골라 합한 값과 뷰티를 곱한 것들 중 최댓값이 답
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

/* 🐣🐥 */
priority_queue<ll, vector<ll>, greater<ll>> pq;
pll arr[300001];
int ap = 0;
int main() {
	int k, n;
	ll hap = 0, cur, ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[i].second, &arr[i].first);
	}
	sort(arr, arr + n, greater<pll>());
	while (ap < n) {
		cur = arr[ap].first;
		while (ap < n && arr[ap].first == cur) {
			pq.push(arr[ap].second);
			hap += arr[ap].second;
			ap++;
		}
		while (pq.size() > k) {
			hap -= pq.top();
			pq.pop();
		}
		ans = max(ans, hap*cur);
	}
	printf("%lld", ans);

	return 0;
}