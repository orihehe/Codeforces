/*
�����⹮��..
cost�� ������������, �ش� ������ �ְ�, �� ��� �Ѵٸ� cost�� ���� ������
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define P pair<ll,ll>
using namespace std;

P cost[100001]; // ���� ����, �ε���
P food[100001]; // ���� ����, ����
ll cp = 1;
int main() {
	ll n, m, x, a, b, tmp;
	ll sum;
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		food[i].first = x; // ����
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		cost[i] = { x,i };
		food[i].second = x; // ���
	}
	sort(cost, cost + n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%lld %lld", &a, &b);
		sum = 0;
		tmp = min(b, food[a].first); // ���ϴ� ���� �ټ��ִ� ��ŭ
		sum += tmp * food[a].second;
		food[a].first -= tmp;
		if (food[a].first < 0) food[a].first = 0;
		b -= tmp;
		while (b > 0 && cp <= n) {
			if (food[cost[cp].second].first <= 0) { // �� �������ٸ�
				cp++; continue;
			}
			ll nx = cost[cp].second;
			tmp = min(b, food[nx].first); // �� �� ���� ��ŭ
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