/*
set에 0~m-1까지 m으로 나눈 나머지 모두를 넣어둔다.
set에 남아있는 원소를 아직 나오지 않은 나머지로 생각하고, 
이 나머지가 나올 수 있는 경우 set에서 삭제해준다.
m이 1000까지 이고, 현재 입력받는 수의 나머지가 0이 아니라면 최소 1개의 원소는 지워지게 된다. -> O(m^2)
s에서 바로 지우면 현재 수로 지운 것을 또 현재 수의 경우로 생각하게 되니 현재 수의 경우가 끝난 뒤 지워준다.
*/
#include <cstdio>
#include <set>
using namespace std;

set<int> s, tmp;
set<int> ::iterator iter;
int main() {
	int n, m, x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) s.insert(i);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		tmp.clear();
		for (iter = s.begin(); iter != s.end();iter++) {
			if (x%m <= *iter && s.find(*iter - (x % m)) == s.end()) {
				tmp.insert(*iter);
			}
			else if (x%m > *iter && s.find((m - x%m + *iter)%m) == s.end()) {
				tmp.insert(*iter);
			}
		}
		for (iter = tmp.begin(); iter != tmp.end();iter++) {
			s.erase(*iter);
		}
		s.erase(x%m);
		if (s.find(0) == s.end()) {
			return !printf("YES");
		}
	}
	printf("NO");

	return 0;
}