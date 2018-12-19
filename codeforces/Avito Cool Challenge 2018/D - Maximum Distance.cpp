/*
���� ���ظ� �� �߾��µ� MooTube������ Ǯ���� ������ ������ �� ���϶�� ���� �����ߴ�.
a���� b�� ���� ��θ� �����ϴ� ������ �� ���� ū ���� ���
a���� b�� ���� ���� ��ε��� ��� �� ���� ���� ���� �Ÿ�
Ư�� �������� �־����� �� �������� �ٸ� Ư������(�ƹ��ų�)�� ���� �Ÿ��� ���� �� ���� ���ϴ� �����̴�.
�ڱ� �ڽŰ� �̾��� ������ �ְ� a,b�� ������ ���� �� ���� �� �ִ�.

���� �迭 e�� ���������� �ְ� �������� ���� �� ��� Ư�������� �̾��� ��(��� ���� ����)���� ������ ����.
��� �̾����� ���� ����� �� Ư���������� �ٸ� Ư������������ ���� �� �Ÿ��̴�.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define P pair<int,int>
using namespace std;

struct edge {
	int val, a, b;
};
bool operator < (edge& e1, edge& e2) {
	return e1.val < e2.val;
}

int q, a, b, r, n, m, etop;
edge e[200000];
int spe[100001];
int parent[100001];

int find_root(int cur) {
	if (parent[cur] == cur) return cur;
	return parent[cur] = find_root(parent[cur]);
}

bool same_set(int v1, int v2) {
	v1 = find_root(v1);
	v2 = find_root(v2);
	if (v1 == v2) return true;
	return false;
}

void merge(int v1, int v2) {
	v1 = find_root(v1);
	v2 = find_root(v2);
	if (v1 == v2) return;

	parent[v1] = v2;
}

void kruskal() {
	int lastUSA = n - 2, ans;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i < q; i++) {
		// ��� Ư�� ������ ���� �θ� ��������
		if (same_set(spe[i], spe[i - 1])) continue;
		i--;
		merge(e[etop].a, e[etop].b);
		ans = e[etop].val;
		etop++;
	}
	for (int i = 0; i < q; i++) printf("%d ", ans);
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &spe[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &r);
		e[i] = { r,a,b };
	}
	sort(e, e + m);
	kruskal();

	return 0;
}