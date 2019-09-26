/*
수가 등장한 횟수를 저장해두고, 추가할 때마다 pq에 넣는다.
pq의 top이 그 수의 등장횟수와 맞지 않다면 pop, 
가장 많이 등장한 수 외의 수가 k보다 많다면 l값을 빼준다.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int arr[200001], use[100001]; // 수 등장 횟수
priority_queue<pii> pq;
int main() {
	int n, m, k, l=0, mx = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		pq.push({ ++use[arr[i]],arr[i] });
		while (true) {
			if (use[pq.top().second] != pq.top().first) {
				pq.pop();
			}
			else if (i - l + 1 - pq.top().first > k) {
				use[arr[l++]]--;
			}
			else break;
		}
		mx = max(mx, pq.top().first);
	}
	printf("%d", mx);

	return 0;
}