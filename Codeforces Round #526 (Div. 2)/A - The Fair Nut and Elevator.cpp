/*
x�� ��� ��츦 �غ���.
i�� x, tmp�� �� �������� ���� �Ҹ� ���� ���̴�.
abs(i-j)�� ó�� ���������� ��ġ���� j�� ���� ��, j-1�� j������ 1������ ��,
i-1�� 1������ x�� ���� ���̴�. �ٽ� x������ ���ư��� ����.  
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, arr[101], minE = 987654321, tmp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp += (abs(i - j) + j - 1 + i - 1) * 2 * arr[j];
		}
		minE = min(minE, tmp);
	}
	printf("%d", minE);

	return 0;
}