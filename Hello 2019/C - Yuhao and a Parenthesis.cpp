/*
( )�� �����ϴ� ��ȣ�� �����ְ� ���� (, ) ���� ���� ���ش�.
���� (, ) �ΰ� ��� ���´ٸ� �ٸ� �ϳ��� ���ĵ� �´� ��ȣ�� ���� �� �����Ƿ� ����
(�� ������ ������, )�� ������ ����� �迭�� �ְ� �̹� ¦�� �� �ִٸ� ���� ze�� ī��Ʈ ���ش�.
�迭���� ������ ���� ������, ����� ������ ���ְ� +ze/2 ���� ����Ѵ�.
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