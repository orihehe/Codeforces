/*
앞에서부터 한 짝을 고정시켜두고, 다른 한 짝을 옆으로 가져온다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, arr[200], cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 2 * n; i++) {
		bool tmp = false;
		for (int j = 2 * n - 1; j > i; j--) {
			if (arr[j] == arr[i]) tmp = true;
			else if (tmp) {
				cnt++;
				swap(arr[j], arr[j+1]);
			}
		}
	}
	printf("%d", cnt);

	return 0;
}