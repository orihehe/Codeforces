/*
keg�� �����Ͽ� ���� ���� ������ ���̸�ŭ s�� ���ش�. �� ���� �ڿ� s�� �������
���� ���� ���� ���� �ȴ�. s�� �����ִٸ� �� ����� �Ѵ�.
���keg n���� ���� ���� ����ŭ ���������Ƿ� ���� ���� ���� ���� ũ�� �Ƿ���
�� keg���� 1���;� s�� ä��°� �ݺ��ϸ� �ȴ�. ���� s/n���͸� ���� ���� ������ ���� ���� ���̴�.
���� �� ���� ������� s�� �� ä�� �� ����.
*/
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	long long n, s, arr[1001];
	scanf("%lld %lld", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n, greater<long long>());
	for (int i = 0; i < n - 1; i++) {
		s -= arr[i] - arr[n - 1];
	}
	if (s <= 0) printf("%lld", arr[n - 1]);
	else if (arr[n - 1] >= (s + n - 1) / n) {
		printf("%lld", arr[n - 1] - ((s + n - 1) / n));
	}
	else printf("-1");

	return 0;
}