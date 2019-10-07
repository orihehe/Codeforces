#include <cstdio>
#include <cmath>
#define ll long long
long double PI = 3.141592653589793238462643383279502884197;
using namespace std;

/* 🐣🐥 */
int main() {
	ll h, l;
	long double y;
	scanf("%lld %lld", &h, &l);
	y = sqrt(h*h + l * l);
	long double tmp = asin((double)l / y) * 180 / PI;
	tmp = tmp - (90 - tmp);

	printf("%.8Lf", l*tan(tmp * PI / 180));

	return 0;
}