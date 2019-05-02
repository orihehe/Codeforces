/*
앞에서부터 가장 작은 수가 나오도록 하는데, (n-x)
그 수가 남아있지 않다면 다음으로 작게 만들 수와 merge
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[200001], num[200001], p[200001];
int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
int main() {
	int n, x, ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		p[i] = i;
		arr[i] %= n;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		num[x%n]++;
	}
	for (int i = 0; i < n; i++) {
		ans = (n - arr[i]) % n;
		ans = find(ans);
		while (num[ans] == 0) {
			merge(ans, (ans + 1) % n);
			ans = find(ans);
		}
		printf("%d ", (ans + arr[i]) % n);
		num[ans]--;
	}

	return 0;
}