/*
변화량을 부분합으로 저장, 부분합의 최솟값을 mv에 저장해둔다.
use배열은 이 수가 나왔었는지를 체크
최솟값을 더한 값이 n보다 작으면서 한번도 나오지 않았다면 나왔음을 체크해준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[200001], x, mv;
bool use[200001];
int main() {
	int n, ans = 0, mx = 0;
	scanf("%d", &n);
	arr[0] = 0;
	for (int i = 1; i < n; i++) {
		scanf("%lld", &x);
		arr[i] = arr[i - 1] + x;
		mv = min(mv, arr[i]);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] - mv + 1 > n)return !printf("-1");
		else if (use[arr[i] - mv]) return !printf("-1");
		use[arr[i] - mv] = true;
	}
	for (int i = 0; i < n; i++) {
		printf("%lld ", arr[i] - mv + 1);
	}

	return 0;
}