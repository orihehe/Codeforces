#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[100001], cnt;
bool sosu[100001];
int main() {
	for (int i = 2; i <= 100000; i++) {
		if (sosu[i]) continue;
		arr[i] = ++cnt;
		for (int j = 2; j*i <= 100000; j++) {
			if (!arr[i*j]) arr[i*j] = cnt;
			sosu[i*j] = true;
		}
	}

	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) printf("%d ", arr[i]);

	return 0;
}