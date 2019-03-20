/*
앞에있는 boots의 원소를 원소별로 위치를 모두 저장
뒤의 boots의 ? 가 아닌 값중 앞에도 같은 값이 있다면 ans에 넣어준다.
이제 남은 값들을 ?와 매칭
*/
#include <cstdio>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<int> a[27], b[27];
vector<pii> ans;
int main() {
	int n;
	char fr[150002], ba[150002];
	scanf("%d", &n);
	scanf("%s %s", fr, ba);
	for (int i = 0; i < n; i++) {
		if (fr[i] == '?') a[26].push_back(i);
		else a[fr[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if (ba[i] == '?') b[26].push_back(i);
		else if (a[ba[i] - 'a'].size() > 0) {
			ans.push_back({ a[ba[i] - 'a'].back() + 1,i + 1 });
			a[ba[i] - 'a'].pop_back();
		}
		else {
			b[ba[i] - 'a'].push_back(i);
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int v = a[i].size() - 1; v >= 0; v--) {
			if (b[26].size() == 0) break;
			ans.push_back({ a[i][v] + 1, b[26].back() + 1 });
			b[26].pop_back();
		}
	}
	for (int i = 0; i < 27; i++) {
		for (int v = b[i].size() - 1; v >= 0; v--) {
			if (a[26].size() == 0) break;
			ans.push_back({ a[26].back() + 1, b[i][v] + 1 });
			a[26].pop_back();
		}
	}
	printf("%d\n", ans.size());
	for (pii v : ans) {
		printf("%d %d\n", v.first, v.second);
	}

	return 0;
}