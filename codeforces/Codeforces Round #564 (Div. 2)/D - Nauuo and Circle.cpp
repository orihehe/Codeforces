/*
한 노드를 루트노드로 잡고 생각해본다.
교차가 생기지 않으려면 각 노드는 이어진 노드들과 연속적으로 나타나야 한다.
따라서 이어진 노드의 경우의 수 * (노드 수)! 로 구해주고,
이것은 루트를 한 위치에 놓았을 때의 경우이니 *n을 해준다.
*/
#include <cstdio>
#define mod 998244353
using namespace std;

/* 🐣🐥 */
int num[200001];
int main() {
	int n, a, b, ans = 1;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		num[a]++, num[b]++;
	}
	for (int i = 1; i <= n; i++) {
		while (num[i]) {
			ans = 1LL * ans * num[i] % mod;
			num[i]--;
		}
	}
	printf("%d", 1LL * ans*n%mod);

	return 0;
}