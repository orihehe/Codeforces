/*
각 역에 사탕 종류별로 개수를 저장,
열차에 각 역에서 멀리있는 사탕부터 싣는다. 가장 가까운 역을 나중에 가는 게 최소 cost
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int arr[101][101], tmp[101][101], train[101], tc;
int main() {
	int n, m, a, b, cnt, cc = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		tmp[a][b]++;
	}
	for (int i = 1; i <= n; i++) { // 출발
		cnt = 0;// cost
		cc = 0; // 배달 시작한 사탕 수
		tc = 0; // 열차에 있는 사탕 수
		int k = i - 1;
		memcpy(arr, tmp, sizeof(arr));
		while (m - cc>0) {
			if (++k == n + 1) k = 1;
			tc -= train[k]; // k역에 오면 k사탕 내려놓음
			train[k] = 0;
			for (int j = k - 1;; j--) { // 먼것부터 주움
				if (j == 0) j = n;
				if (j == k) break;
				if (arr[k][j]) {
					arr[k][j]--;
					cc++;
					train[j]++;
					tc++;
					break;
				}
			}
			cnt++;
		}
		while (tc > 0) { // 열차에 사탕 남아있다면
			if (++k == n + 1) k = 1;
			tc -= train[k];
			train[k] = 0;
			cnt++;
		}

		printf("%d ", cnt - 1);
	}

	return 0;
}