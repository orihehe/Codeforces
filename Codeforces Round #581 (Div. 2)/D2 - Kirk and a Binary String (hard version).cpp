#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[100002];
int fr[100002], ba[100002];
int num[100002][2];
int main() {
	scanf("%s", st + 1);
	int n = strlen(st + 1);
	for (int i = 1; i <= n; i++) {
		num[i][0] = num[i - 1][0];
		num[i][1] = num[i - 1][1];
		num[i][st[i] - '0']++;
	}
	for (int i = 1; i <= n; i++) 
		fr[i] = max(fr[i - 1] + (st[i] == '1'), num[i][0]);
	for (int i = n; i >= 1; i--)
		ba[i] = max(ba[i + 1] + (st[i] == '0'), num[n][1] - num[i - 1][1]);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (st[i] == '0') continue;
		if (max(fr[i - 1] + num[n][1] - num[i][1], num[i - 1][0] + 1 + cnt + ba[i + 1])
			== fr[n]) st[i] = '0', cnt++;
	}
	printf("%s", st + 1);

	return 0;
}