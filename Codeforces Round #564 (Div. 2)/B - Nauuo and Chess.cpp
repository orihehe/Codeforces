/*
if (n==8)
1 2 3 4



5 6 7 8
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, m;
	scanf("%d", &n);
	m = n / 2 + 1;
	printf("%d\n", m);
	for (int i = 0; i < n / 2; i++)
		printf("%d %d\n", 1, i + 1);
	int cnt = 1;
	for (int i = n / 2; i < n; i++) printf("%d %d\n", m, cnt++);

	return 0;
}