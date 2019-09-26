/*
오름차순 정렬 후 맨앞 두 수와 맨뒤 두 수 중 차이가 큰 수를 제외하면 된다.
제외 후 맨 앞, 맨 뒤 수의 차이가 답이다.
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	sort(arr, arr + n);
	if (n == 2) printf("0");
	else if (arr[n - 1] - arr[n - 2] < arr[1] - arr[0]) {
		printf("%d", arr[n - 1] - arr[1]);
	}
	else printf("%d", arr[n - 2] - arr[0]);

	return 0;
}