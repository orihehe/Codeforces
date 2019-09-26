/*
i가 s와 같을 때 pq에 시험에 대한 정보를 넣어주고, 기한이 짧은 애를 우선하여 준비해준다.
pq에 넣을 때 시험날짜는 겹치지 않으니 미리 ans배열에 넣고,
준비할지 정하는 과정에서 시험 날짜라면 또는 pq가 비어있으면 넘어간다.
날짜가 지났는데 준비해야할 일수가 남았다면 불가능!
*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

/* 🐣🐥 */
struct exam {
	int pb, date, cnt, idx;
	bool operator <(const exam &a) const {
		return date > a.date;
	}
};
bool cmp(exam &a, exam &b) {
	return a.pb < b.pb;
}
int ans[101], ap;
exam arr[101];
priority_queue<exam> pq;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &arr[i].pb, &arr[i].date, &arr[i].cnt);
		arr[i].idx = i + 1;
	}
	sort(arr, arr + m, cmp);
	for (int i = 1; i <= n; i++) {
		while (ap < m && arr[ap].pb == i) {
			ans[arr[ap].date] = m + 1;
			pq.push(arr[ap++]);
		}
		if (pq.empty() || ans[i] != 0) continue;
		else {
			exam tmp = pq.top();
			pq.pop();
			if (tmp.date < i) return !printf("-1");
			ans[i] = tmp.idx;
			tmp.cnt--;
			if (tmp.cnt > 0) pq.push(tmp);
		}
	}
	if (!pq.empty()) return !printf("-1");
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}