#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char A[100001], B[100001];
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s %s", A, B);
		int a = strlen(A), b = strlen(B);
		int idx;
		for (int i = b - 1; i >= 0; i--) {
			if (B[i] == '1') {
				idx = a - b + i;
				break;
			}
		}
		for (int i = idx; i >= 0; i--) {
			if (A[i] == '1') {
				printf("%d\n", idx - i);
				break;
			}
		}
	}

	return 0;
}