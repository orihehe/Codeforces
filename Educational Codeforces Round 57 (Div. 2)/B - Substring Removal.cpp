/*
입력받은 문자열에서 substring 한개를 지운 후의 남은 문자들이 모두 같은 문자가 되도록 만드는 문제.
한개를 지워야 하므로 모두 같은 문자이게 하려면 맨앞이나 맨뒤를 포함하는 경우로 만들 수 있다.
맨앞과 맨뒤에서부터 연속하는 같은 문자의 수의 합+전체 지우기(1)가 답인데
추가로 맨앞 문자와 맨뒤 문자가 같은 경우 다른 문자가 시작된 중앙의 substring을 포함한 substring을 삭제하는 경우의 수가 추가된다.
*/
#include <cstdio>
#include <cstring>
#define ll long long
#define mod 998244353
using namespace std;

char st[200001];
int main() {
	int n;
	ll ans = 1, fc = 1, bc = 1;
	scanf("%d", &n);
	scanf("%s", st);
	char f = st[0], b = st[n - 1];
	for (int i = 1; i < n - 1; i++) {
		if (f == st[i]) fc++;
		else break;
	}
	for (int i = n - 2; i >= 1; i--) {
		if (b == st[i]) bc++;
		else break;
	}
	ans += fc + bc;
	if (f == b) {
		bc--, fc--;
		ans += 1 + bc + fc + bc * fc;
		printf("%lld", ans%mod);
	}
	else {
		printf("%lld", ans%mod);
	}

	return 0;
}