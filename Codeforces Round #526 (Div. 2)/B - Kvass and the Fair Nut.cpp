/*
keg를 정렬하여 가장 작은 값과의 차이만큼 s를 빼준다. 이 과정 뒤에 s가 음수라면
가장 작은 값이 답이 된다. s가 남아있다면 더 따라야 한다.
모든keg n개에 가장 작은 값만큼 남아있으므로 가장 작은 값이 가장 크게 되려면
각 keg에서 1리터씩 s를 채우는걸 반복하면 된다. 따라서 s/n리터를 가장 작은 값에서 빼준 값이 답이다.
만약 뺀 값이 음수라면 s를 다 채울 수 없다.
*/
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	long long n, s, arr[1001];
	scanf("%lld %lld", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n, greater<long long>());
	for (int i = 0; i < n - 1; i++) {
		s -= arr[i] - arr[n - 1];
	}
	if (s <= 0) printf("%lld", arr[n - 1]);
	else if (arr[n - 1] >= (s + n - 1) / n) {
		printf("%lld", arr[n - 1] - ((s + n - 1) / n));
	}
	else printf("-1");

	return 0;
}