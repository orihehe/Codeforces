#include <cstdio>
using namespace std;

/* 🐣🐥 */
int ans[1001][1001];
int main() {
	int n, x = 0;
	scanf("%d", &n);
	for (int k = 0; k < n; k += 4) {
		for (int i = 0; i < n; i++) {
			for (int j = k; j < k + 4; j++) {
				ans[i][j] = x++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}