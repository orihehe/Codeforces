/*
���� ���� ���̰� ���� �ֵ��� �� �̾��ָ� �ȴ�.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;

int arr[100001];
pii dis[100001];
int main() {
	int n, m, k, cnt = 0, pp, last = 0;
	ll sum = 0;
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d", &arr[0]);
	for (int i = 1; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	// dis�迭�� ���� ���� �ʺ�� ��ġ ����
	for (int i = 1; i < n; i++) {
		dis[i] = { arr[i] - arr[i - 1] , i };
	}
	pp = n - 1;
	sort(dis, dis + n); // ����
	while (cnt < k - 1) { // �ڿ������� 
		cnt++;
		sum += arr[dis[pp].second - 1] - arr[last] + 1;
		last = dis[pp--].second;
	}
	sum += arr[n - 1] - arr[last] + 1;
	printf("%lld", sum);

	return 0;
}