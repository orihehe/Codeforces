/*
쌓인 아래 부분이 1부터 오름차순인 경우 바로 만드는게 가능한지 봐주고,
불가능하다면 1이 내 손에 온 시점 뒤로 가장 빨리 만들 수 있는 시점을 찾는다.
*/
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int my[200001];
bool mm[200001];
pii f[200001];
int main() {
	int n, cnt = -1, on = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &my[i]);
		mm[my[i]] = true;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &f[i].first);
		f[i].second = i + 1;
		if (f[i].first == 1) on = i + 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (f[i].first == 1) {
			if (i == 0) return !printf("0");
			cnt = f[n - 1].first + 1;
			break;
		}
		if (f[i].first == 0 || f[i].first - 1 != f[i - 1].first) break;
	}

	if (cnt != -1) {
		bool suc = true;
		for (int i = 0; i < n; i++) {
			if (f[i].first == 1) break;
			if (f[i].first == 0) continue;
			if (f[i].second > f[i].first - cnt) {
				suc = false;
				break;
			}
		}
		if (suc) return !printf("%d", n - cnt + 1);
	}
	int ps = 0;
	for (int i = on; i < n; i++) {
		if (f[i].first == 0) continue;
		ps = max(ps, f[i].second - on - f[i].first + 1);
	}
	printf("%d", on + ps + n);

	return 0;
}