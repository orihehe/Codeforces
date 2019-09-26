/*
수가 클수록 제곱수는 엄청 커진다.
따라서 두 수씩 묶어주는데, 그 합들의 차이가 가장 작은 값을 찾아 계산해준다.
sort 후 앞뒤 수를 묶어주면 끝
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[300001], sum;
int main() {
	int n, l, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	l = 0; r = n - 1;
	while (l <= r) {
		sum += (arr[l] + arr[r]) * (arr[l] + arr[r]);
		l++; r--;
	}
	printf("%lld", sum);

	return 0;
}