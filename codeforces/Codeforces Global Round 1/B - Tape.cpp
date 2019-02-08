/*
끊긴 지점 사이가 넓은 애들을 안 이어주면 된다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;

int arr[100001];
pii dis[100001];
int main() {
	int n, m, k, cnt = 0, pp, last = 0;
	ll sum = 0;
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d", &arr[0]);
	for (int i = 1; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	// dis배열에 끊긴 지점 너비와 위치 저장
	for (int i = 1; i < n; i++) {
		dis[i] = { arr[i] - arr[i - 1] , i };
	}
	pp = n - 1;
	sort(dis, dis + n); // 정렬
	while (cnt < k - 1) { // 뒤에서부터 
		cnt++;
		sum += arr[dis[pp].second - 1] - arr[last] + 1;
		last = dis[pp--].second;
	}
	sum += arr[n - 1] - arr[last] + 1;
	printf("%lld", sum);

	return 0;
}