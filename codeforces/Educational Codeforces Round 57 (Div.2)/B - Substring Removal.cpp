/*
�Է¹��� ���ڿ����� substring �Ѱ��� ���� ���� ���� ���ڵ��� ��� ���� ���ڰ� �ǵ��� ����� ����.
�Ѱ��� ������ �ϹǷ� ��� ���� �����̰� �Ϸ��� �Ǿ��̳� �ǵڸ� �����ϴ� ���� ���� �� �ִ�.
�Ǿհ� �ǵڿ������� �����ϴ� ���� ������ ���� ��+��ü �����(1)�� ���ε�
�߰��� �Ǿ� ���ڿ� �ǵ� ���ڰ� ���� ��� �ٸ� ���ڰ� ���۵� �߾��� substring�� ������ substring�� �����ϴ� ����� ���� �߰��ȴ�.
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