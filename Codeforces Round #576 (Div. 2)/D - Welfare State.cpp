/*
1번 쿼리는 현재 값과, 그 값이 된 시점을 저장해두고
2번 쿼리는 세그트리에 그 값이 들어온 시점에 값을 저장한다.
쿼리 수행 후 현재 i가 변경된 마지막 시점+1~q까지의 최댓값을 세그트리에서 찾아준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[200001][2];
int tree[525144];
void update(int idx, int s, int e, int k, int val) {
	if (s > k || e < k) return;
	if (s == e) {
		tree[idx] = val; return;
	}
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}
int find(int idx, int s, int e, int l, int r) {
	if (s > r || e < l)return 0;
	if (l <= s && e <= r) return tree[idx];
	return max(find(idx * 2, s, (s + e) / 2, l, r)
		, find(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main() {
	int n, q, mx = 0, cm, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &cm, &a);
		if (cm == 1) {
			scanf("%d", &b);
			arr[a - 1][0] = b;
			arr[a - 1][1] = i;
		}
		else {
			update(1, 1, q, i, a);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", max(arr[i][0], find(1, 1, q, arr[i][1] + 1, q)));
	}

	return 0;
}