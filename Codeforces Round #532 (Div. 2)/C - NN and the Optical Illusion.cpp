/*
sin함수에 X(각도)* pi/180 을 곱해서 넣으면 원하는 sinX를 구할 수 있다.
문제에서 안쪽 원의 반지름(r)과 바깥원의 개수(n)가 주어진다. 구하려는 것은 바깥원의 반지름 x
바깥 원의 중점과 안쪽 원의 중점을 연결하고 바깥원끼리의 접선을 그리면 안쪽원의 중점을 지난다.
바깥원의 중점에서 접선으로 선을 그으면 접선과 수직으로 만난다.
안쪽 원의 중점에있는 각은 360/(2*n), 이것을 X로 두면
sinX=x/(x+r)
식을 전개해서 x를 구했다.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	double n, r;
	scanf("%lf %lf", &n, &r);
	double ss, x, s = 360 / (n * 2) * 3.141592653 / 180;
	ss = sin(s);
	x = (r*ss) / (1 - ss);

	printf("%.7lf", x);

	return 0;
}