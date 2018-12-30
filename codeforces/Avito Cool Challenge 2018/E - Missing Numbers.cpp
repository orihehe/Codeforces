/*
���� �������� ���� �������� ������ �ְ�, 2,4,6,... ��° ���� �־����� ���� ������ ã�� ������.
������ ������ 1,4,9,16 ... �� ���̰� 3, 5, 7, ...���� 2�� �þ��.
���� ���������� ù ���̿������� �ڵ��󳪿��� ���̸� ����(tmp) �־��� ��(x)�� ���Ѵ�.
���� x�� tmp���� ũ�ٸ� ù ���̸� ���ְ� ���� ����(last)�� ���Ѵ�, �۴ٸ� �ڵ������ ���̸� �����ش�.
�� ������ ������ ���Ҵ� 1�̻��̹Ƿ� last�� 0�� �ƴϰ� tmp�� x�� ���� �� �����ش�.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	int n;
	ll x, f = -1, tmp, last, ff = -1;
	vector<ll> ans;
	scanf("%d", &n);
	for (int i = 0; i < n / 2; i++) {
		scanf("%lld", &x); 
		f += 2; ff = f;
		tmp = f; last = 0; 
		while (tmp > 0) {
			if (x == tmp && last!=0) {
				break;
			}
			if (x > tmp) {
				f += 2;
				tmp += f; 
			}
			else {
				tmp -= ff;
				last += ff;
				ff += 2;
			}
		}
		if (tmp <= 0) {
			printf("No"); return 0;
		}
		ans.push_back(last);
		ans.push_back(tmp);
	}
	printf("Yes\n");
	for (ll v : ans) printf("%lld ", v);

	return 0;
}