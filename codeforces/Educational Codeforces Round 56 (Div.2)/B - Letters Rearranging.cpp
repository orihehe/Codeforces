/*
�� ���ڸ� �ִ� ��츦 �����ϰ� �׳� �����ϸ� �Ӹ������ �ƴϰ� �ȴ�.
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