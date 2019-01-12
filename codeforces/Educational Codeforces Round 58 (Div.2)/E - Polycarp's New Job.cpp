/*
������ ����, ������ ū ���� m1, ���� ���� m2�� �д�.
�Է¹��� ������ ����, ������ ū�� x ������ y�� �ΰ� m1, m2�� ��
���� �ϳ��� m1, m2���� ������ �� ������ ���� �� ����.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int q, x, y, m1 = 0, m2 = 0;
	char cm;
	scanf("%d", &q);
	getchar();
	while (q--) {
		scanf("%c %d %d", &cm, &x, &y);
		getchar();
		if (x < y) swap(x, y);
		if (cm == '+') {
			if (m1 < x) {
				m1 = x;
			}
			if (m2 < y) {
				m2 = y;
			}
		}
		else if (cm == '?') {
			if (m1 > x || m2 > y) printf("NO\n");
			else printf("YES\n");
		}
	}

	return 0;
}