/*
대회 시간에 못 풀었는데, 전혀 모르겠어서 풀이를 여쭤봤다ㅜㅜ
(x/k)*(x%k)=n 에서 n과 k가 주어지고 x를 구하는 문제.
x%k를 i로 두는데, n은 1이상이므로 0이 될 수 없고 k로 나눈 나머지는 k이상의 수가 될 수 없기 때문에
i의 범위는 1<=i<k 이다.
i로 변경 후 위의 식은 x=n/i*k로 바꿀 수 있다. 
주의할 점은 (x/k)*i=n 에서 n은 x/k 연산에서 나머지가 버려진 값의 결과인 것이다.
따라서 x=n/i*k에서 x값을 구한 것은 나머지값이 빠진 값이다. 
본래의 x값은 x=n/i*k+i로 구할 수 있다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
	ll n, k;
	ll x = 987987987987987;
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i < k; i++) {
		if (n%i == 0) {
			x = min(x, n / i * k + i);
		}
	}
	printf("%lld", x);

	return 0;
}