/*
x1<= a <= y1, x2<= b <= y2, a!=b �� a,b ���ϱ�
a�� x1�� ���ϰ� b���� x1�� �ٸ� x2ory2 ���
*/
#include <cstdio>
using namespace std;

int main() {
	int n, x1, y1, x2, y2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		bool s = false;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d %d\n", x1, x1 == x2 ? y2 : x2);
	}

	return 0;
}