/*
그룹별로 최소 m개의 원소, k개의 그룹이 나와야 한다.
m*k개의 원소만이 뷰티값에 영향을 줄 수 있다.
따라서 값이 큰 m*k개의 원소를 미리 골라두고, 각 그룹에 m개씩 들어가도록 한다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
bool mx[200001];
pii arr[200001];
int main() {
	int n, m, k, pc = 0 , cnt = 0;
	ll sum = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = n - 1; i >= n-m*k; i--) {
		mx[arr[i].second] = true;
		sum += arr[i].first;
	}
	printf("%lld\n", sum);
	for (int i = 0; i < n; i++) {
		if (mx[i]) cnt++;
		if (cnt == m) {
			printf("%d ", i + 1);
			cnt = 0;
			pc++;
		}
		if (pc == k - 1) break;
	}

	return 0;
}