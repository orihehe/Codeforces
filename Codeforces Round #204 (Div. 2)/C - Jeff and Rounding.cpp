/*
�Ҽ��� �Ʒ� ���鸸 �迭�� ����, 0�� ��� ������ ���ش�.
a�� ��, b�� ���� ������ ��, a�� �ø�, b�� ������ ���� �����Ѵ�.
0�� a�� ��, b�� �ڿ� ���̴� ��츦 ����Ͽ� ��� ��� �� �ּڰ��� ã�� ���
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[4001], ap;
int main() {
	int n, ans=20000000, cnt0 = 0, a = 0, b = 0, ptr, sum = 0;
	double x;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%lf", &x);
		x += 1e-8;
		if ((int)(x * 1000) % 1000 == 0) cnt0++;
		else {
			arr[ap++] = (int)(x * 1000) % 1000;
			sum += arr[ap - 1];
		}
	}
	sort(arr, arr + ap);
	ptr = (ap+1) / 2-(cnt0+1) / 2;
	ptr = ptr < 0 ? 0 : ptr;
	for (int i = 0; i < ptr; i++) a += arr[i];
	b = sum - a;
	ans = min(ans, abs(ptr * 1000 - a - b));
	ans = min(ans, abs((ap - ptr) * 1000 - a - b));
	for (int i = ptr; i < ap - ptr; i++) {
		a += arr[i];
		b -= arr[i];
		ans = min(ans, abs((i+1) * 1000 - a - b));
	}

	printf("%d.%03d", ans / 1000, ans % 1000);

	return 0;
}