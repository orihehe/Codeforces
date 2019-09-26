/*
pair의 왼쪽이 작은 원소끼리, 오른쪽이 작은 원소끼리만 고를 수 있다.

(왼쪽 < 오른쪽)인 원소는 오른쪽 원소가 더 크니 오른쪽이 큰 순으로 정렬한다면
i+1의 원소의 왼쪽이 i 원소의 오른쪽보다 클 수가 없다. == 모두 이을 수 있다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
struct info {
	int first, second, idx;
};
vector<info> up, dw;
bool cmp1(info a, info b) {
	return a.second > b.second;
}
bool cmp2(info a, info b) {
	return a.second < b.second;
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a < b) up.push_back({ a,b,i + 1 });
		else dw.push_back({ a,b,i + 1 });
	}
	if (up.size() > dw.size()) {
		sort(up.begin(), up.end(), cmp1);
		printf("%d\n", up.size());
		for (info v : up) printf("%d ", v.idx);
	}
	else {
		sort(dw.begin(), dw.end(), cmp2);
		printf("%d\n", dw.size());
		for (info v : dw) printf("%d ", v.idx);
	}

	return 0;
}