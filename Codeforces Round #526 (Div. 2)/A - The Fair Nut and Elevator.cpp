/*
x의 모든 경우를 해본다.
i는 x, tmp는 각 층마다의 전력 소모를 더한 값이다.
abs(i-j)는 처음 엘리베이터 위치에서 j층 가는 값, j-1은 j층에서 1층가는 값,
i-1은 1층에서 x층 가는 값이다. 다시 x층으로 돌아가기 때문.  
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, arr[101], minE = 987654321, tmp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp += (abs(i - j) + j - 1 + i - 1) * 2 * arr[j];
		}
		minE = min(minE, tmp);
	}
	printf("%d", minE);

	return 0;
}