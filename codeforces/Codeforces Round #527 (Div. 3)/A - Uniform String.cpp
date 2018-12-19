/*
k이하의 문자들 이용한 같은 문자가 최소한으로 등장하는 문자열 출력문제이다.
번갈아서 출력해줬다.
*/

#include <cstdio>
using namespace std;

int main() {
	int n, t, k, cnt;
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			printf("%c", cnt%k + 'a');
			cnt++;
		}
		printf("\n");
	}

	return 0;
}