/*
1~n���� ���� ��� ���� �� ���� ������ �����ϴ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int num[100001];
int main() {
	int n, m, he = 0, x;
	int cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		if (num[x] == 0) cnt++; // x�� ������ ó�� ������ �� ����
		num[x]++;
		if (cnt == n) { // ������ �ѹ����� ������ ��
			cnt = 0;
			for (int j = 1; j <= n; j++) {
				num[j]--; // ���� ����
				if (num[j] != 0) cnt++;
			}
			printf("1");
		}
		else {
			printf("0");
		}
	}

	return 0;
}