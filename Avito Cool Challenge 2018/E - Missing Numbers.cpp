/*
현재 수까지의 합이 제곱수인 순열이 있고, 2,4,6,... 번째 수만 주어지면 원래 순열을 찾는 문제다.
연속한 제곱수 1,4,9,16 ... 는 차이가 3, 5, 7, ...으로 2씩 늘어난다.
따라서 사용되지않은 첫 차이에서부터 뒤따라나오는 차이를 더해(tmp) 주어진 값(x)과 비교한다.
만약 x가 tmp보다 크다면 첫 차이를 빼주고 이전 원소(last)에 더한다, 작다면 뒤따라오는 차이를 더해준다.
이 과정을 순열의 원소는 1이상이므로 last가 0이 아니고 tmp와 x가 같을 때 멈춰준다.
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