/*
내 모자와 다른 모자를 쓴 사람의 수(a) -> 같은 모자를 쓴 사람 (본인포함) : n-a 명이 돼야 한다.
a의 개수를 세고 n-a개를 만족했을 때 같은 모자를 posi배열에 넣었다.
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