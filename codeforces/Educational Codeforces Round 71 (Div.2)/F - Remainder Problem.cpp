/*
수 범위를 적절히 나눠준다.
w보다 큰 수는 500000/x번 인덱스의 값을 직접 더해주고
w이하의 수는 1번 쿼리에서의 인덱스가 x가 w이하인 2번쿼리에서 어느 y에 추가되는지를 구해준다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[500001];
ll pls[711][711];
int main() {
	int q, cm, a, b;
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d %d", &cm, &a, &b);
		if (cm == 1) {
			for (int i = 1; i <= 710; i++) {
				pls[i][a%i] += b;
			}
			arr[a] += b;
		}
		else {
			ll sum = 0;
			if (a <= 710) {
				sum = pls[a][b];
			}
			else {
				for (int i = b; i <= 500000; i += a)
					sum += arr[i];
			}
			printf("%lld\n", sum);
		}
	}

	return 0;
}