/*
괄호 문제와 비슷한 방식으로 풀면 된다.
한 글자씩 입력 받아 앞에 같은 글자가 있다면 없애주고 카운트.
*/
#include <cstdio>
using namespace std;

char st[100001];
int tp = 0, cnt = 0;
int main() {
	char x;
	while (~scanf("%c", &x)) {
		if (st[tp] == x) {
			tp--; cnt++;
		}
		else {
			st[++tp] = x;
		}
	}
	if (cnt % 2) printf("Yes");
	else printf("No");

	return 0;
}