#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
char st[101][102];
int arr[101][101];
int dist[101][101];
int vec[1000001];
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", st[i]);
		for (int j = 0; j < n; j++) {
			if (st[i][j] == '0') arr[i][j] = INF;
			else arr[i][j] = 1;
		}
		arr[i][i] = 0;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &vec[i]);
		vec[i]--;
	}
	int tmp = 2;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 2; j < m; j++) {
			if (arr[vec[i]][vec[j]] == j - i) {
				vec[j - 1] = -1;
				cnt++;
			}
			else {
				i = j - 2;
				break;
			}
		}
	}
	printf("%d\n", m - cnt);
	for (int i = 0; i < m; i++) {
		if (vec[i] != -1) printf("%d ", vec[i] + 1);
	}

	return 0;
}