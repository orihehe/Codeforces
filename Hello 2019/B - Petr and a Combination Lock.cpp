/*
�Է¹��� ����ŭ ���������� ������ �������� ������ ����Ž��
360�� ����� ��� ���� 0���� ���ƿ� ��
*/
#include <cstdio>
using namespace std;

int n, arr[16];
bool can;
void dfs(int cur, int sum) {
	if (cur == n) {
		if (sum % 360 == 0) {
			can = true;
		}
		return;
	}
	dfs(cur + 1, sum + arr[cur]);
	dfs(cur + 1, sum - arr[cur]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0, 0);
	if (can) printf("YES");
	else printf("NO");

	return 0;
}