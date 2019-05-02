/*
양쪽 수를 보며 작은 수를 선택한다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[200001], sp, num;
char st[200001];
int main() {
	int n, l, r, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	l = 0, r = n - 1;
	while (true) {
		if (l != -1 && r != -1) {
			if (arr[l] > arr[r]) {
				if (arr[r] > num) {
					st[sp++] = 'R';
					ans++;
					num = arr[r--];
				}
				else r = -1;
			}
			else {
				if (arr[l] > num) {
					st[sp++] = 'L';
					ans++;
					num = arr[l++];
				}
				else l = -1;
			}
		}
		else if (l != -1) {
			if (arr[l] > num) {
				st[sp++] = 'L';
				ans++;
				num = arr[l++];
			}
			else l = -1;
		}
		else if (r != -1) {
			if (arr[r] > num) {
				st[sp++] = 'R';
				ans++;
				num = arr[r--];
			}
			else r = -1;
		}
		else break;
	}
	printf("%d\n", ans);
	printf("%s", st);

	return 0;
}