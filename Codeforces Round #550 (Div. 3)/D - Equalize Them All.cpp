/*
가장 많이 나온 수로 다 만들어준다.
그 수들의 위치를 모두 큐에 넣고 주변 애들을 적절한 연산을 골라 해준다.
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
int arr[200001], cnt[200001];
struct info {
	int cm, i, ii;
};
vector<info> ans;
queue<int> q;
int main() {
	int n, mv, mcnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
		if (mcnt < cnt[arr[i]]) {
			mcnt = cnt[arr[i]];
			mv = arr[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == mv) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur + 1 < n && arr[cur + 1] != mv) {
			if (arr[cur + 1] > mv) {
				ans.push_back({ 2,cur + 1,cur });
			}
			else ans.push_back({ 1,cur + 1,cur });
			arr[cur + 1] = mv;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && arr[cur - 1] != mv) {
			if (arr[cur - 1] > mv) {
				ans.push_back({ 2,cur - 1,cur });
			}
			else ans.push_back({ 1,cur - 1,cur });
			arr[cur - 1] = mv;
			q.push(cur - 1);
		}
	}
	printf("%d\n", ans.size());
	for (info v : ans) {
		printf("%d %d %d\n", v.cm, v.i + 1, v.ii + 1);
	}

	return 0;
}