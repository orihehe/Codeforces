/*
x1<= a <= y1, x2<= b <= y2, a!=b 인 a,b 구하기
a는 x1로 구하고 b에서 x1과 다른 x2ory2 출력
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