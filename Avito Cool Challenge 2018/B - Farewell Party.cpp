/*
�� ���ڿ� �ٸ� ���ڸ� �� ����� ��(a) -> ���� ���ڸ� �� ��� (��������) : n-a ���� �ž� �Ѵ�.
a�� ������ ���� n-a���� �������� �� ���� ���ڸ� posi�迭�� �־���.
*/
#include <cstdio>
#include <vector>
using namespace std;

int n, arr[100000];
vector<int> cnt[100001];
int posi[100000];
int main() {
	int hat = 1, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i]].push_back(i);
		if (cnt[arr[i]].size() == n - arr[i]) {
			for (int &v : cnt[arr[i]]) {
				posi[v] = hat;
				sum++;
			}
			hat++;
			cnt[arr[i]].clear();
		}
	}
	if (sum < n) {
		printf("Impossible");
	}
	else {
		printf("Possible\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", posi[i]);
		}
	}

	return 0;
}