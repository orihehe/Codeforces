/*
중심을 하나 찾아 사방으로 이어진 별을 없앤 뒤 남은 별이 있는지 확인
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char b[501][502];
int main() {
	int n, m;
	bool flag = false;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (b[i][j] == '*' && b[i][j - 1] == '*' && b[i][j + 1] == '*'&& b[i - 1][j] == '*' && b[i + 1][j] == '*') {
				int nr = i - 1, nc = j;
				flag = true;
				b[i][j] = '.';
				while (nr >= 0) {
					if (b[nr][nc] == '.') break;
					b[nr--][nc] = '.';
				}
				nr = i + 1, nc = j;
				while (nr < n) {
					if (b[nr][nc] == '.') break;
					b[nr++][nc] = '.';
				}
				nr = i, nc = j - 1;
				while (nc >= 0) {
					if (b[nr][nc] == '.') break;
					b[nr][nc--] = '.';
				}
				nr = i, nc = j + 1;
				while (nc < m) {
					if (b[nr][nc] == '.') break;
					b[nr][nc++] = '.';
				}
			}
			if (flag) break;
		}
		if (flag) break;
	}
	if (!flag) return !printf("NO");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (b[i][j] == '*') return !printf("NO");
	}
	printf("YES");

	return 0;
}