/*
배열을 반으로 나눠서 오른쪽부터 정렬 해줄것이다.

1자리의 원소는 오른쪽 모두와 스왑할 수 있으니 
만약 원하는 원소가 왼쪽에 있다면 n자리에 보낸 뒤 1로, 
오른쪽에 있다면 바로 1로 보낸 뒤 원하는 자리로 보내준다.

왼쪽차례인데 원소가 왼쪽에 섞여있을 것이다. 
왼쪽은 n자리와 모두 스왑 가능이니 n으로 보낸 뒤 원하는 자리로 보내준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int arr[300001], idx[300002];
vector<pii> ans;
int main() {
	int n, qks;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		idx[arr[i]] = i;
	}
	qks = n / 2;
	for (int i = n / 2 + 1; i <= n; i++) {
		if (arr[i] == i) continue;
		int ii = idx[i];
		if (ii <= qks) {
			ans.push_back({ ii,n });
			swap(arr[ii], arr[n]);
			idx[arr[ii]] = ii;
			idx[arr[n]] = n;

			ans.push_back({ 1,n });
			swap(arr[1], arr[n]);
			idx[arr[1]] = 1;
			idx[arr[n]] = n;
		}
		else {
			ans.push_back({ 1,ii });
			swap(arr[1], arr[ii]);
			idx[arr[1]] = 1;
			idx[arr[ii]] = ii;
		}
		ans.push_back({ 1,i });
		swap(arr[1], arr[i]);
		idx[arr[1]] = 1;
		idx[arr[i]] = i;
	}
	for (int i = 1; i <= qks; i++) {
		if (arr[i] == i) continue;
		int ii = idx[i];
		if (ii != n) {
			ans.push_back({ ii,n });
			swap(arr[ii], arr[n]);
			idx[arr[ii]] = ii;
			idx[arr[n]] = n;
		}

		ans.push_back({ n,i });
		swap(arr[n], arr[i]);
		idx[arr[n]] = n;
		idx[arr[i]] = i;
	}

	printf("%d\n", ans.size());
	for (pii v : ans) printf("%d %d\n", v.first, v.second);

	return 0;
}