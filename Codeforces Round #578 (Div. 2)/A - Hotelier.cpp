#include <cstdio>
using namespace std;

/* 🐣🐥 */
bool hot[10];
char st[100001];
int main() {
	int n;
	scanf("%d %s", &n, st);
	for (int i = 0; i < n; i++) {
		if (st[i] <= '9' && st[i] >= '0') {
			hot[st[i] - '0'] = false;
		}
		else if (st[i] == 'L') {
			for (int i = 0; i < 10; i++) {
				if (!hot[i]) {
					hot[i] = true;
					break;
				}
			}
		}
		else {
			for (int i = 9; i >= 0; i--) {
				if (!hot[i]) {
					hot[i] = true;
					break;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (hot[i]) printf("1");
		else printf("0");
	}

	return 0;
}