#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, k, arr[101], maxS = 0, sum = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for (int j = 1; j <= k; j++) {
		int e = 0, s = 0, idx = j, tmp;
		tmp = sum;
		arr[j] == 1 ? e++ : s++;
		while (idx + k <= n) {
			idx += k;
			arr[idx] == 1 ? e++ : s++;
		}
		tmp -= e; tmp += s;
		maxS = max(maxS, abs(tmp));
	}
	printf("%d", maxS);

	return 0;
}