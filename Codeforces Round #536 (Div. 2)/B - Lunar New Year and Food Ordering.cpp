/*
구데기문제..
cost를 오름차순정렬, 해당 음식을 주고, 더 줘야 한다면 cost가 작은 순으로
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define P pair<ll,ll>
using namespace std;

P cost[100001]; // 음식 가격, 인덱스
P food[100001]; // 음식 개수, 가격
ll cp = 1;
int main() {
	ll n, m, x, a, b, tmp;
	ll sum;
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		food[i].first = x; // 개수
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		cost[i] = { x,i };
		food[i].second = x; // 비용
	}
	sort(cost, cost + n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%lld %lld", &a, &b);
		sum = 0;
		tmp = min(b, food[a].first); // 원하는 음식 줄수있는 만큼
		sum += tmp * food[a].second;
		food[a].first -= tmp;
		if (food[a].first < 0) food[a].first = 0;
		b -= tmp;
		while (b > 0 && cp <= n) {
			if (food[cost[cp].second].first <= 0) { // 다 떨어졌다면
				cp++; continue;
			}
			ll nx = cost[cp].second;
			tmp = min(b, food[nx].first); // 줄 수 있을 만큼
			sum += tmp * food[nx].second;
			food[nx].first -= tmp;
			if (food[nx].first < 0) food[nx].first = 0;
			b -= tmp;
		}
		if (b > 0) printf("0\n");
		else printf("%lld\n", sum);
	}

	return 0;
}