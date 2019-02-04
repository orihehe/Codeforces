/*
map�� key������ ���� �� ���� ���̸� �����Ѵ�
x-1���� ��������ʴٸ� 1��, x-1���� �ִٸ� x-1������ ���� + 1 ����
*/
#include <cstdio>
#include <map>
using namespace std;

map<int, int> mp;
int arr[200001];
int main() {
	int n, x, maxL=0, maxV=0, cur;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		arr[i] = x;
		if (mp.find(x - 1) == mp.end()) {
			mp[x] = 1;
		}
		else {
			mp[x] = mp[x - 1] + 1;
		}
		if (maxL < mp[x]) {
			maxL = mp[x];
			maxV = x;
		}
	}
	cur = maxV - maxL + 1;
	printf("%d\n", maxL);
	for (int i = 1; i <= n; i++) {
		if (arr[i] == cur) {
			printf("%d ", i);
			cur++;
		}
	}

	return 0;
}