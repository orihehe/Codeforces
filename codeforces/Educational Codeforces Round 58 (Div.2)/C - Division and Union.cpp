/*
�� �����̶� ��ġ�� ���� �׷��� �ȴ�.
���� ���������� ���� �׷���� ã�´�.
���� r�� ���� l(arr[i].first)���� ������ �ٸ� �׷��̴� �׷��� ���ְ� ������ ����Ѵ�.
������ �׷츸 2�� ǥ�����ְ� �������� 1�� ǥ���ϸ� ��
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct info {
	int first, second, idx;
};
bool operator <(info &a, info &b) {
	if (a.first == b.first && a.second == b.second) return a.idx < b.idx;
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
info arr[200001];
int ans[200001];
int main() {
	int t, n, r, cnt, loc;
	bool div;
	scanf("%d", &t);
	while (t--) {
		r = -1; cnt = 0; loc = -1;
		div = false;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &arr[i].first, &arr[i].second);
			arr[i].idx = i;
		}
		sort(arr, arr + n);
		for (int i = 0; i < n; i++) {
			if (r >= arr[i].first) {
				if (r < arr[i].second)
					r = arr[i].second;
			}
			else {
				cnt++;
				loc = i;
				r = arr[i].second;
			}
		}
		if (cnt == 1) {
			printf("-1\n");
		}
		else {
			for (int i = 0; i < loc; i++) {
				ans[arr[i].idx] = 1;
			}
			for (int i = loc; i < n; i++) {
				ans[arr[i].idx] = 2;
			}
			for (int i = 0; i < n; i++) printf("%d ", ans[i]);
			printf("\n");
		}
	}

	return 0;
}