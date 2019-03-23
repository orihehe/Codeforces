/*
<와 >는 뾰족한 방향의 다른 문자를 없앨 수 있다.
구해야 할것은 모든 문자를 같게 만드는데 <와 >를 이용하지 않고 삭제해야만 하는 개수이다.

왼쪽 끝의 연속한 <개수와 오른쪽 끝의 연속한 >개수 중 작은 것이 답이된다.
왼쪽 끝의 <나 오른쪽 끝의 >는 마지막까지 지워질 수 없기 때문
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, t, l, r;
	char st[101];
	scanf("%d", &t);
	while (t--) {
		l = r = 0;
		scanf("%d", &n);
		scanf("%s", st);
		for (int i = 0; i < n; i++) {
			if (st[i] == '<') l++;
			else break;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (st[i] == '>') r++;
			else break;
		}
		printf("%d\n", min(l, r));
	}

	return 0;
}