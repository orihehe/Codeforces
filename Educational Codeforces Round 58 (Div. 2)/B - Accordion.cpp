/*
아코디언 형태는 [::]이 기본, ::의 중간에 |가 몇개든 들어갈 수 있음.
가장 앞 [:, 가장 뒤 :]일때 가장 긴 아코디언이 된다.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char st[500002];
bool start, c1, c2, end;
int main() {
	scanf("%s", st);
	int len = strlen(st), cnt = 0, res, re = 0;
	for (int i = 0; i < len; i++) {
		if (!start) {
			if (st[i] == '[') start = true;
		}
		else if (start && !c1) {
			if (st[i] == ':') c1 = true;
		}
		// 앞쪽 [:가 나온 뒤부터 |의 개수를 센다.
		else if (start && c1) {
			if (st[i] == '|') {
				cnt++;
			}
			if (st[i] == ':') {
				res = 4 + cnt; c2 = true;
			}
			if (c2 && st[i] == ']') { // :] 형태로 닫혔을 때 센 값을 re에 저장
				re = res; c2 = false;
			}
		}
	}
	if (re == 0) {
		printf("-1");
	}
	else {
		printf("%d", re);
	}

	return 0;
}