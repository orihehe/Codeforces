/*
양쪽 수를 비교하며 작은 수를 선택하는데, 
같은 수일 경우 한쪽을 선택하면 그 후론 한 쪽만 선택가능
따라서 양쪽의 경우를 해본다.
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
			if (arr[l] == arr[r]) {
				break;
			}
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

	int rmx = 0, lmx = 0, rnum = num, lnum = num;
	while (arr[r] > rnum) {
		rmx++;
		rnum = arr[r--];
	}
	while (arr[l] > lnum) {
		lmx++;
		lnum = arr[l++];
	}
	if (rmx > lmx) {
		ans += rmx;
		while (rmx--) st[sp++] = 'R';
	}
	else {
		ans += lmx;
		while (lmx--) st[sp++] = 'L';
	}
	printf("%d\n", ans);
	printf("%s", st);

	return 0;
}