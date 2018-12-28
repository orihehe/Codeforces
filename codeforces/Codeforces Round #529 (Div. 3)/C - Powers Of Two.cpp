/*
2의 제곱수 k개의 합으로 숫자 n을 나타내는 문제이다.
n을 먼저 이진수로 바꿨을 때 1의 개수가 가장 적은 2의 제곱수 개수로 나타낸 n이다.
바꾼 후 가장 큰 2의 제곱수를 2로 나눠 두개로 만드는 방식을 k개가 만들어질 때까지 반복하면 된다.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, k, arr[32], at = 0, cnt = 0, p = 31;
	memset(arr, 0, sizeof(arr));
	scanf("%d %d", &n, &k);
	while (n > 0) {
		if (n % 2 == 1) {
			arr[at++] = 1;
			cnt++;
		}
		else arr[at++] = 0;
		n /= 2;
	}
	if (cnt > k) { // 가장 적은 개수로 나타낸 것이 k보다 클 때
		printf("NO");
	}
	else {
		while (cnt < k) {
			while (p>0 && arr[p] == 0) p--;
			if (p == 0) break;
			arr[p]--;
			arr[p - 1] += 2; cnt++;
		}
		// 전부 1인데 개수가 k개보다 적다면
		if (p == 0) printf("NO");
		else {
			printf("YES\n");
			for (int i = 0; i < 32; i++) {
				while (arr[i] > 0) {
					printf("%d ", (int)pow(2, i));
					arr[i]--;
				}
			}

		}
	}

	return 0;
}