/*
수들을 모두 XOR 한 값이 양수이려면 켜진 비트의 개수가 홀수개여야 한다.
따라서 행에서 비트별로 켜진 것을 벡터에 저장,
만약 한 비트의 켜진 개수가 열의 개수와 같다면 그 행에서는 무조건 그 비트가 켜져야 한다는 뜻이다.
따라서 무조건 켜진 개수를 비트별로 관리하고, 켜질 수 있는 것 또한 비트별로 관리.
적절히 복원해주면 된다.
*/
#include <cstdio>
#include <vector>
using namespace std;

/* 🐣🐥 */
int arr[501][501];
vector<int> vec[501][12][2], ans; // i번째줄, k번째 비트, 있으면 1, 없으면 0
int cnt[12], kk[12]; //  cnt 는 무조건, kk는 있는거
int main() {
	int n, m, x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &x);
			for (int k = 0; k < 12; k++) {
				if (x % 2) vec[i][k][1].push_back(j + 1);
				else vec[i][k][0].push_back(j + 1);
				x /= 2;
			}
		}
		for (int k = 0; k < 12; k++) {
			if (vec[i][k][1].size() == m) { // 무조건 있어야
				cnt[k]++;
			}
			if (vec[i][k][1].size() != 0) kk[k]++;
		}
	}
	for (int k = 0; k < 12; k++) {
		if (cnt[k] % 2) {
			printf("TAK\n");
			for (int i = 0; i < n; i++) {
				if (vec[i][k][1].size() == m)
					printf("%d ", vec[i][k][1][0]);
				else
					printf("%d ", vec[i][k][0][0]);
			}
			return 0;
		}
		else if (kk[k]>cnt[k]) {
			int lm = 0;
			printf("TAK\n");
			for (int i = 0; i < n; i++) {
				if (vec[i][k][1].size() == m)
					printf("%d ", vec[i][k][1][0]);
				else if (lm == 0 && vec[i][k][1].size() > 0) {
					printf("%d ", vec[i][k][1][0]);
					lm = 1;
				}
				else {
					printf("%d ", vec[i][k][0][0]);
				}
			}
			return 0;
		}
	}
	printf("NIE");

	return 0;
}