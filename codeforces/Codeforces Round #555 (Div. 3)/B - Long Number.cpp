/*
앞에서부터 현재 수보다 크게 바꿀 수 있는 시점에서부터 작아지는 시점까지 바꿔준다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[200001];
int num[10];
int main() {
	int n, len, w = 0;
	bool s = false;
	scanf("%d %s", &n, st);
	for (int i = 1; i < 10; i++) scanf("%d", &num[i]);
	len = strlen(st);
	for (int i = 0; i < len; i++) {
		if (num[st[i] - '0'] > st[i] - '0' || (num[st[i] - '0'] == st[i] - '0' && s)) {
			st[i] = num[st[i] - '0'] + '0';
			s = true;
		}
		else if (s) break;
	}
	printf("%s", st);

	return 0;
}