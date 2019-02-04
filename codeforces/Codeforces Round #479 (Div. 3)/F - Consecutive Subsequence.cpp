/*
map에 key까지의 가장 긴 수열 길이를 저장한다
x-1값이 들어있지않다면 1을, x-1값이 있다면 x-1까지의 길이 + 1 저장
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