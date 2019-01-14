/*
1~n까지 수가 모두 있을 때 문제 출제가 가능하다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int num[100001];
int main() {
	int n, m, he = 0, x;
	int cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		if (num[x] == 0) cnt++; // x번 문제가 처음 나왔을 때 세줌
		num[x]++;
		if (cnt == n) { // 문제가 한번씩은 나왔을 때
			cnt = 0;
			for (int j = 1; j <= n; j++) {
				num[j]--; // 문제 출제
				if (num[j] != 0) cnt++;
			}
			printf("1");
		}
		else {
			printf("0");
		}
	}

	return 0;
}