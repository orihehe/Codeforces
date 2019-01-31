/*
���� Ŭ���� �������� ��û Ŀ����.
���� �� ���� �����ִµ�, �� �յ��� ���̰� ���� ���� ���� ã�� ������ش�.
sort �� �յ� ���� �����ָ� ��
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[300001], sum;
int main() {
	int n, l, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	l = 0; r = n - 1;
	while (l <= r) {
		sum += (arr[l] + arr[r]) * (arr[l] + arr[r]);
		l++; r--;
	}
	printf("%lld", sum);

	return 0;
}