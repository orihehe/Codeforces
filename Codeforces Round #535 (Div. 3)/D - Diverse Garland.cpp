/*
������ ���� �ٸ� ���� �ǵ��� �ϴ� ����
���� ���� ���� ���� ���ٸ� ���� ���� ���� ���� �ٸ� ���� ���ڷ� �ٲ��ָ� �ȴ�.
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