/*
set�� 0~m-1���� m���� ���� ������ ��θ� �־�д�.
set�� �����ִ� ���Ҹ� ���� ������ ���� �������� �����ϰ�, 
�� �������� ���� �� �ִ� ��� set���� �������ش�.
m�� 1000���� �̰�, ���� �Է¹޴� ���� �������� 0�� �ƴ϶�� �ּ� 1���� ���Ҵ� �������� �ȴ�. -> O(m^2)
s���� �ٷ� ����� ���� ���� ���� ���� �� ���� ���� ���� �����ϰ� �Ǵ� ���� ���� ��찡 ���� �� �����ش�.
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