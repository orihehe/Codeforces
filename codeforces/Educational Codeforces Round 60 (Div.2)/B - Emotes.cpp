/*
가장 큰 값이 m번 나올때마다 그다음 큰 값을 채워주면 된다.
따라서 k를 m+1한 값으로 나눠준 값이 다음 큰 값이 나오는 횟수 
나머지는 가장 큰 값으로
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[200001], sum, mV, sV;
int n, k, m;
int main() {
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	m++;
	sort(arr, arr + n);
	mV = arr[n - 1], sV = arr[n - 2];
	sum += sV * (k / m);
	k -= k / m;
	sum += mV * k;
	printf("%lld", sum);

	return 0;
}