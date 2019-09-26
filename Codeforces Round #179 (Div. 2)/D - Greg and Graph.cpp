/*
없애는 정점이 주어지는데, 이것을 없는 상태에서 하나씩 추가하는 것으로 생각하여 푼다.
사용한 정점으로만 이루어진 거리를 더하여 출력
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[501][501];
vector<int> vec;
vector<ll> prt;
bool use[501];
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		vec.push_back(--x);
	}
	reverse(vec.begin(), vec.end());
	for (int k : vec) {
		use[k] = true;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				if (!use[j] || !use[i]) continue;
				ans += arr[i][j];
			}
		}
		prt.push_back(ans);
	}
	reverse(prt.begin(), prt.end());
	for (ll v : prt) printf("%lld ", v);

	return 0;
}