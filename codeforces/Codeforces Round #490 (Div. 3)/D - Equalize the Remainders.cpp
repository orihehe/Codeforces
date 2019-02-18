/*
수가 모자란 c를 가장 조금 증가시키는 남는 c로 만들어 준다.
*/
#include <cstdio>
#include <vector>
#include <map>
#define ll long long
using namespace std;

/* 🐣🐥 */
vector<int> arr[200001];
int rm[200001], ori[200001];
int n, m;
ll cnt;
map<int, int> ump, nmp; // ump : 남는거 , nmp : 필요한거
map<int, int> ::iterator iter, tmp;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ori[i]);
		rm[ori[i]%m]++;
		arr[ori[i]%m].push_back(i); // 인덱스 넣어둠
	}
	for (int i = 0; i < m; i++) {
		if (rm[i] > n/m) {
			ump[i] = rm[i] - n / m;
		}
		else if (rm[i] < n/m) {
			nmp[i] = n / m - rm[i];
		}
	}
	for (iter = nmp.begin(); iter != nmp.end(); iter++) {
		while (iter->second > 0) {
			tmp = ump.lower_bound(iter->first);
			if (tmp == ump.begin()) {
				tmp = --(ump.end());
				cnt += iter->first- tmp->first + m;
				ori[arr[tmp->first].back()] += iter->first - tmp->first + m;
				arr[tmp->first].pop_back();
			}
			else {
				--tmp;
				cnt += iter->first - tmp->first;
				ori[arr[tmp->first].back()] += iter->first - tmp->first;
				arr[tmp->first].pop_back();
			}
			tmp->second--;
			iter->second--;
			if (tmp->second == 0) ump.erase(tmp);
		}
	}
	printf("%lld\n", cnt);
	for (int i = 0; i < n; i++) {
		printf("%d ", ori[i]);
	}

	return 0;
}