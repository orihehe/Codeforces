/*
큰 수부터 차례로 봐주면서 (l~l) ~ (l~n)의 값을 (l-1~l-1) ~ (l-1~n)에서 재사용
l-1값이 없다면 (l~l) ~ (l~n)의 값과 같고,
있다면 여기에 (n - (l-1) + 1)를 더한다. 
그 주변에 l-1 이상의 값이 있다면 r이 k이상일 때 값이 빠져야함
*/
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[100002];
vector<int> vec[100002];
ll ans, tmp;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		vec[arr[i]].push_back(i);
	}
	for (int i = n; i >= 1; i--) {
		for (int v : vec[i]) {
			tmp = tmp + (n - i + 1);
			if (arr[v - 1] >= i) {
				tmp -= (n - arr[v - 1] + 1);
			}
			if (arr[v + 1] > i) {
				tmp -= (n - arr[v + 1] + 1);
			}
		}
		ans += tmp;
	}
	printf("%lld", ans);

	return 0;
}