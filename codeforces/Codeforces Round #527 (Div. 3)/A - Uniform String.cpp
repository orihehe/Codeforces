/*
k������ ���ڵ� �̿��� ���� ���ڰ� �ּ������� �����ϴ� ���ڿ� ��¹����̴�.
�����Ƽ� ��������.
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