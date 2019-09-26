/*
2�� ������ k���� ������ ���� n�� ��Ÿ���� �����̴�.
n�� ���� �������� �ٲ��� �� 1�� ������ ���� ���� 2�� ������ ������ ��Ÿ�� n�̴�.
�ٲ� �� ���� ū 2�� �������� 2�� ���� �ΰ��� ����� ����� k���� ������� ������ �ݺ��ϸ� �ȴ�.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, k, arr[32], at = 0, cnt = 0, p = 31;
	memset(arr, 0, sizeof(arr));
	scanf("%d %d", &n, &k);
	while (n > 0) {
		if (n % 2 == 1) {
			arr[at++] = 1;
			cnt++;
		}
		else arr[at++] = 0;
		n /= 2;
	}
	if (cnt > k) { // ���� ���� ������ ��Ÿ�� ���� k���� Ŭ ��
		printf("NO");
	}
	else {
		while (cnt < k) {
			while (p>0 && arr[p] == 0) p--;
			if (p == 0) break;
			arr[p]--;
			arr[p - 1] += 2; cnt++;
		}
		// ���� 1�ε� ������ k������ ���ٸ�
		if (p == 0) printf("NO");
		else {
			printf("YES\n");
			for (int i = 0; i < 32; i++) {
				while (arr[i] > 0) {
					printf("%d ", (int)pow(2, i));
					arr[i]--;
				}
			}

		}
	}

	return 0;
}