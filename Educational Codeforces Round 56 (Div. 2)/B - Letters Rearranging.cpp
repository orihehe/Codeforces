/*
한 문자만 있는 경우를 제외하고 그냥 나열하면 팰린드롬이 아니게 된다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t, len;
	char st[1001];
	int alpha[26];
	scanf("%d", &t);
	while (t--) {
		memset(alpha, 0, sizeof(alpha));
		scanf("%s", st);
		len = strlen(st);
		for (int i = 0; i < len; i++) {
			alpha[st[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (alpha[i] == len) {
				printf("-1");
				break;
			}
			for (int j = 0; j < alpha[i]; j++) {
				printf("%c", i + 'a');
			}
		}
		printf("\n");
	}

	return 0;
}