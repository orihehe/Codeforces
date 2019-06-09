/*
홀수, 짝수인 원소가 각 1개 이상일 때 오름차순 정렬가능.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[100001];
int n, oc, ec;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] % 2) ec++;
		else oc++;
	}
	if (ec != 0 && oc != 0)
		sort(arr, arr + n);

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);

	return 0;
}