/*
Petya는 앞쪽의 8을 없애는 것이 최선이다.
따라서 뒷쪽 10글자를 없애고 8개수를 세서 n/2개보다 많다면 Vasya는 무조건 이길 수 있다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char st[100001];
int main() {
	int n, cnt = 0;
	scanf("%d %s", &n, st);
	n -= 10;
	for (int i = 0; i < n; i++) {
		if (st[i] == '8') cnt++;
	}
	if (cnt > n / 2) {
		printf("YES");
	}
	else printf("NO");

	return 0;
}