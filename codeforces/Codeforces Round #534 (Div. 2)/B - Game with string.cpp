/*
��ȣ ������ ����� ������� Ǯ�� �ȴ�.
�� ���ھ� �Է� �޾� �տ� ���� ���ڰ� �ִٸ� �����ְ� ī��Ʈ.
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