/*
수열의 모든 원소의 gcd값이 x, 원소의 합이 y인 수열의 가짓수를 구하는 문제
이것을 gcd 1, 합 y/x인 문제로 바꾸면 
1의 배수로 이루어진 합이 y/x인 수열에서 x의배수 (x는 y/x의 약수)로 이루어진 경우를 없애주면
gcd 1인 수열의 가짓수를 구할 수 있다.  
이때 1의 배수로 이루어진 합이 y/x인 수열의 가짓수는 2^(y/x-1) 이고
x의 배수 또한 같은 방식으로 1의 배수로 만들어주어 포함배제를 하면 된다.

이 때 y/x값의 약수의 약수는 y/x의 약수 이므로 메모이제이션을 통해 다시 계산하지 않도록 한다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
vector<int> tt;
map<int, int> mp;
int mul(int a, int b) { // a^b
	int ret = 1;
	while (b > 0) {
		if (b % 2) {
			ret = (int)(1LL * ret * a%mod);
		}
		a = (int)(1LL * a * a%mod);
		b /= 2;
	}
	return ret;
}
void prime(int a) { // 약수
	int lm = sqrt(a);
	for (int i = 2; i <= lm; i++) {
		if (a%i == 0) {
			tt.push_back(i);
			if (a / i != i)
				tt.push_back(a / i);
		}
	}
}
int dfs(int len) {
	if (mp.find(len) != mp.end()) return mp[len];
	int ret = mul(2,len-1)-1;
	for (int v : tt) {
		if (v >= len) break;
		if (len%v == 0)
			ret = (ret - dfs(len / v) + mod) % mod;
	}
	return mp[len] = ret;
}
int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (y%x != 0) return !printf("0");
	y /= x;
	prime(y);
	sort(tt.begin(), tt.end());
	mp[1] = 1;
	printf("%d", dfs(y));

	return 0;
}