#include <cstdio>
using namespace std;

char b[501][501];
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (b[i][j] == 'X' && b[i - 1][j - 1] == 'X' && b[i - 1][j + 1] == 'X'
				&& b[i + 1][j - 1] == 'X' && b[i + 1][j + 1] == 'X') cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}