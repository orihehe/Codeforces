/*
( )가 성립하는 괄호는 없애주고 남는 (, ) 수를 각각 세준다.
만약 (, ) 두개 모두 남는다면 다른 하나와 합쳐도 맞는 괄호를 만들 수 없으므로 제외
(의 개수는 음수로, )의 개수는 양수로 배열에 넣고 이미 짝이 다 있다면 따로 ze에 카운트 해준다.
배열에서 절댓값이 같은 음수값, 양수값 개수를 세주고 +ze/2 값을 출력한다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> arr;
int main() {
	int n, l, r, len, ze = 0, ans = 0, le, ri;
	char st[500001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		l = r = 0;
		scanf("%s", st);
		len = strlen(st);
		stack<char> sta;
		for (int j = 0; j < len; j++) {
			if (st[j] == '(') {
				sta.push('(');
			}
			else if (st[j] == ')') {
				if (!sta.empty()) {
					sta.pop();
				}
				else {
					l++;
				}
			}
		}
		if (!sta.empty()) {
			r = sta.size();
		}
		if (l != 0 && r == 0) {
			arr.push_back(-l);
		}
		if (r != 0 && l == 0) {
			arr.push_back(r);
		}
		if (r == 0 && l == 0)
			ze++;
	}
	sort(arr.begin(), arr.end());
	ans += ze / 2;
	int s = arr.size();
	le = 0; ri = s - 1;
	while (le<s && ri >= 0 && arr[le]<0 && arr[ri]>0) {
		int ln = -arr[le], rn = arr[ri];
		if (ln == rn) {
			ans++;
			le++, ri--;
		}
		else if (ln < rn) {
			ri--;
		}
		else le++;
	}
	printf("%d", ans);

	return 0;
}