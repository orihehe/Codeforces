/*
�Ұ����� ���� �����Ƿ� �޺κ��� �ִ��� ũ��, ���� �ִ��� �۰� �����ߴ�.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

ll n, arr[100000], ans[200000];
int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n / 2; i++) {
		scanf("%lld", &arr[i]);
	}
	ans[n - 1] = arr[0];
	ans[0] = 0;
	for (int i = 1; i < n / 2; i++) {
		if (arr[i] > arr[i - 1]) {
			ans[n - i - 1] = ans[n - i];
			ans[i] = arr[i] - ans[n - i - 1];
		}
		else {
			ans[i] = ans[i - 1];
			ans[n - i - 1] = arr[i] - ans[i];
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%lld ", ans[i]);
	}

	return 0;
}