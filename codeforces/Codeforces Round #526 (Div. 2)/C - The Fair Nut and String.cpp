/*
�߰��� b�� ���� a�� ������ ������ ���� 
b�� ���´ٸ� (��������� ��� * b���� a�� �� + a�� ��)�� i�ε��� ������ ������ ���̴�.
���� �����ϴµ��� ���� �ɷȴ� �Ф�
*/
#include <cstdio>
#include <cstring>
#define mod 1000000007
#define ll long long
#define MAX 100001
using namespace std;

int main() {
	char st[MAX];
	bool bb = false;
	ll last = 0, cur = 0, sum = 0, cntA = 0;

	scanf("%s", st);
	int len = strlen(st);
	for (int i = 0; i < len; i++) {
		if (st[i] == 'a') {
			cntA++;
		}
		else if (st[i] == 'b') {
			if (last == 0) {
				last = cntA;
				cntA = 0;
			}
			else if (cntA>0) {
				last = (last + last * cntA + cntA) % mod;
				cntA = 0;
			}
		}
	}
	if (last == 0) {
		last = cntA;
		cntA = 0;
	}
	else if (cntA>0) {
		last = (last + last * cntA + cntA) % mod;
		cntA = 0;
	}
	printf("%lld", last);

	return 0;
}