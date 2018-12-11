/*
중간에 b가 없는 a의 연속의 개수를 세고 
b가 나온다면 (현재까지의 경우 * b뒤의 a의 수 + a의 수)가 i인덱스 까지의 순열의 수이다.
문제 이해하는데에 오래 걸렸다 ㅠㅠ
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