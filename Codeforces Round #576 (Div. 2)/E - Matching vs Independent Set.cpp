/*
Matching을 만들 수 있는 간선을 그리디하게 먼저 찾아준다.
간선 수가 모자랄 경우 선택하지 않은 정점들 사이 간선이 존재하지 않으니
IndSet은 그 정점들 중 n개를 출력해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<pii> vec;
vector<int> ans;
bool use[300001];
int main() {
	int t, n, m, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		vec.clear(); ans.clear();
		for (int i = 1; i <= 3 * n; i++) use[i] = false;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			vec.push_back({ a,b });
		}
		int cnt = 0, sz = vec.size();
		for (int i = 0; i < sz; i++) {
			pii v = vec[i];
			if (!use[v.first] && !use[v.second]) {
				cnt++;
				ans.push_back(i + 1);
				use[v.first] = use[v.second] = true;
			}
			if (cnt == n) break;
		}
		if (cnt == n) {
			printf("Matching\n");
			for (int v : ans) printf("%d ", v);
		}
		else {
			printf("IndSet\n");
			cnt = 0;
			for (int i = 1; i <= 3 * n; i++) {
				if (!use[i]) {
					printf("%d ", i);
					cnt++;
				}
				if (cnt == n) break;
			}
		}
		printf("\n");
	}

	return 0;
}