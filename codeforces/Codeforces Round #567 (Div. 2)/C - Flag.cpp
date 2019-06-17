/*
층마다 같은 높이를 가지고 인접한 층과 다른 색을 가지는 국기 가짓수를 찾는 문제.
num배열에 세로로 동일한 색의 연속한 개수를 저장

위, 아래 층은 연속한 것 모두 선택하지 않아도 되지만, 가운데는 연속한 것 모두 선택해야한다.
따라서 가운데로 정할 층을 고른 뒤, 위 아래가 그 연속한 개수만큼 있는지 확인,
확인 후 옆으로 같은 조합을 찾아준다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
char b[2002][1002];
int num[2002][1002];
bool use[2002][1002];
int main() {
	int n, m;
	ll ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n + 1; i++) scanf("%s", b[i]);
	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n + 1; i++) {
			if (b[i - 1][j] == b[i][j]) num[i][j] = num[i - 1][j] + 1;
			else num[i][j] = 1;
		}
	}
	int r;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < m; j++) {
			if (use[i][j]) continue;
			if (b[i][j] != b[i + 1][j]) {
				r = j;
				int v = num[i][j];
				if (b[i - v][j] != b[i][j] && num[i - v][j] >= v
					&& b[i + v][j] != b[i][j] && num[i + v][j] == v) {
					use[i][j] = true;
					for (int k = j + 1; k < m; k++) {
						if (b[i][k] != b[i][j] || b[i - v][k] != b[i - v][j] || b[i + v][k] != b[i + v][j]) break;
						if (num[i][k] != v || num[i - v][k] < v || num[i + v][k] != v) break;
						r = k;
						use[i][k] = true;
					}
					r = r - j + 1;
					ll tmp = 0;
					while (r) {
						tmp += r;
						r--;
					}
					ans += tmp;
				}
			}
		}
	}
	printf("%lld", ans);

	return 0;
}