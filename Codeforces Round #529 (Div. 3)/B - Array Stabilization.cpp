/*
�������� ���� �� �Ǿ� �� ���� �ǵ� �� �� �� ���̰� ū ���� �����ϸ� �ȴ�.
���� �� �� ��, �� �� ���� ���̰� ���̴�.
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