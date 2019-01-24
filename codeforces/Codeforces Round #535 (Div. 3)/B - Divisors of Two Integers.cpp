/*
a와 b의 약수들이 모두 arr배열에 들어가 있는 상태.
가장 큰 수가 a일것은 자명하므로 가장 큰 수를 하나 선택한다.
그 수의 약수들을 지워준다(0으로 만듦). 겹치는 약수가 있을 수 있으니 무슨 수를 지웠는지 체크
남은 수들 중 가장 큰수가 b가 된다.
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