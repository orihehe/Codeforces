/*
지폐의 가로, 세로중 큰 것을 m1, 작은 것을 m2에 둔다.
입력받은 지갑의 가로, 세로중 큰것 x 작은것 y에 두고 m1, m2와 비교
둘중 하나라도 m1, m2보다 작으면 그 지갑엔 넣을 수 없다.
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