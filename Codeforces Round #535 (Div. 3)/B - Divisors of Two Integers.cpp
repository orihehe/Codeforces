/*
a�� b�� ������� ��� arr�迭�� �� �ִ� ����.
���� ū ���� a�ϰ��� �ڸ��ϹǷ� ���� ū ���� �ϳ� �����Ѵ�.
�� ���� ������� �����ش�(0���� ����). ��ġ�� ����� ���� �� ������ ���� ���� �������� üũ
���� ���� �� ���� ū���� b�� �ȴ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

bool di[10001];
int arr[130];
int main() {
	int n, maxV = 0, maxV2 = 0;;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		maxV = max(maxV, arr[i]);
	}
	for (int i = 0; i < n; i++) {
		if (!di[arr[i]] && maxV%arr[i] == 0) {
			di[arr[i]] = true;
			arr[i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			maxV2 = max(maxV2, arr[i]);
		}
	}
	printf("%d %d", maxV, maxV2);

	return 0;
}