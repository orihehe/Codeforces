/*
홀수일 경우 :
나머지가 1인 원소를 정중앙에 배치,
남은 원소들 중 4보다 큰 값을 골라 배치,
남은 원소들 중 2보다 큰 값을 골라 배치
짝수일 경우 : 
남은 원소들 중 4보다 큰 값을 골라 배치
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[1001], ans[20][20], ap;
int n, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n*n; i++) {
		scanf("%d", &x);
		arr[x]++;
	}
	if (n % 2) {//홀수
		for (int i = 1; i <= 1000; i++) {
			if (arr[i] % 2) {
				ans[n / 2][n / 2] = i;
				arr[i]--;
				break;
			}
		}
		ap = 0;
		if (ans[n / 2][n / 2] == 0) return !printf("NO");
		for (int i = 0; i < n / 2; i++) {
			for (int j = i; j < n / 2; j++) {
				while (ap <= 1000) {
					if (arr[ap] - 4 >= 0) {
						arr[ap] -= 4;
						break;
					}
					ap++;
				}
				if (ap == 1001) return !printf("NO");
				ans[i][j] = ans[i][n - j - 1]
					= ans[n - i - 1][j] = ans[n - i - 1][n - j - 1] = ap;
			}
		}
		for (int i = 0; i < n / 2 - 1; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				while (ap <= 1000) {
					if (arr[ap] - 4 >= 0) {
						arr[ap] -= 4;
						break;
					}
					ap++;
				}
				if (ap == 1001) return !printf("NO");
				ans[j][i] = ans[j][n - i - 1]
					= ans[n - j - 1][i] = ans[n - j - 1][n - i - 1] = ap;
			}
		}
		ap = 0;
		for (int i = 0; i < n / 2; i++) {
			while (ap <= 1000) {
				if (arr[ap] - 2 >= 0) {
					arr[ap] -= 2;
					break;
				}
				ap++;
			}
			if (ap == 1001) return !printf("NO");
			ans[i][n / 2] = ans[n - i - 1][n / 2] = ap;
			while (ap <= 1000) {
				if (arr[ap] - 2 >= 0) {
					arr[ap] -= 2;
					break;
				}
				ap++;
			}
			if (ap == 1001) return !printf("NO");
			ans[n / 2][i] = ans[n / 2][n - i - 1] = ap;
		}
	}
	else {
		ap = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i; j < n / 2; j++) {
				while (ap <= 1000) {
					if (arr[ap] - 4 >= 0) {
						arr[ap] -= 4;
						break;
					}
					ap++;
				}
				if (ap == 1001) return !printf("NO");
				ans[i][j] = ans[i][n - j - 1]
					= ans[n - i - 1][j] = ans[n - i - 1][n - j - 1] = ap;
			}
		}
		for (int i = 0; i < n / 2 - 1; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				while (ap <= 1000) {
					if (arr[ap] - 4 >= 0) {
						arr[ap] -= 4;
						break;
					}
					ap++;
				}
				if (ap == 1001) return !printf("NO");
				ans[j][i] = ans[j][n - i - 1]
					= ans[n - j - 1][i] = ans[n - j - 1][n - i - 1] = ap;
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}