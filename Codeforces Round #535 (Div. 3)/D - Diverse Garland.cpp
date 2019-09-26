/*
연속한 색이 다른 색이 되도록 하는 문제
현재 색과 이전 색이 같다면 다음 색과 현재 색과 다른 남은 문자로 바꿔주면 된다.
*/
#include <cstdio>
using namespace std;

char st[200001];
char co[3] = { 'R','G','B' };
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	scanf("%s", st);
	for (int i = 1; i < n - 1; i++) {
		if (st[i] == st[i - 1]) {
			for (int j = 0; j < 3; j++) {
				if (co[j] != st[i - 1] && co[j] != st[i + 1]) {
					st[i] = co[j]; cnt++;
					break;
				}
			}
		}
	}
	if (st[n - 1] == st[n - 2]) {
		for (int j = 0; j < 3; j++) {
			if (co[j] != st[n - 2]) {
				st[n - 1] = co[j]; cnt++;
				break;
			}
		}
	}
	printf("%d\n%s", cnt, st);

	return 0;
}