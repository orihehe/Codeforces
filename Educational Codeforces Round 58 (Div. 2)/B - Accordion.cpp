/*
���ڵ�� ���´� [::]�� �⺻, ::�� �߰��� |�� ��� �� �� ����.
���� �� [:, ���� �� :]�϶� ���� �� ���ڵ���� �ȴ�.
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
		// ���� [:�� ���� �ں��� |�� ������ ����.
		else if (start && c1) {
			if (st[i] == '|') {
				cnt++;
			}
			if (st[i] == ':') {
				res = 4 + cnt; c2 = true;
			}
			if (c2 && st[i] == ']') { // :] ���·� ������ �� �� ���� re�� ����
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