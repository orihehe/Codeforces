/*
현재 노드의 서브트리에 x가 있다 - now
1번 쿼리로 구한 거리로 그 거리의 노드 체크 - dd
dd에서 구한 노드의 교집합 배열 - my
x 후보를 절반 이상 가진 가장 작은 서브트리의 루트 - next, 구하는 함수 - find

next안에 답이 있는지 체크는 next와 now의 루트에서부터 거리와 x로의 거리를 통해 알 수 있다.
후보를 반씩 줄여나가 찾아준다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[200001], my, tmp;
int visited[200001], dist[200001];
void dd(int cur, int cnt, int p) {
	if (cnt == 0) {
		visited[cur]++;
		return;
	}
	for (int v : vec[cur]) {
		if (p != v) 
			dd(v, cnt - 1, cur);
	}
}
int find(int cur, int &nn) {
	int ret = visited[cur]==2;
	for (int v : vec[cur]) {
		if (dist[v] > dist[cur]) {
			ret += find(v, nn);
		}
	}
	if (ret * 2 >= (int)my.size()) {
		nn = cur;
		return -1000;
	}
	return ret;
}
void init(int cur, int cnt, int p) {
	dist[cur] = cnt;
	for (int v : vec[cur]) {
		if (p != v)
			init(v, cnt + 1, cur);
	}
}
int main() {
	int n, a, b, now = 1, next, nwd, nxd;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
		my.push_back(i);
	}
	init(1, 0, 1);
	my.push_back(n);
	bool flag = true;
	while (true) {
		if (flag) {
			printf("d %d\n", now);
			fflush(stdout);
			scanf("%d", &nwd);
			memset(visited, 0, sizeof(visited));
			dd(now, nwd, now);
			tmp.clear();
			for (int v : my) {
				if (visited[v]) {
					tmp.push_back(v);
					visited[v]++;
				}
			}
			my = tmp;
			flag = false;
		}
		if (my.size() == 1) {
			printf("! %d", my[0]);
			fflush(stdout);
			return 0;
		}
		find(now, next);
		if (now == next) {
			printf("s %d\n", now);
			fflush(stdout);
			scanf("%d", &now);
			flag = true;
			continue;
		}
		printf("d %d\n", next);
		fflush(stdout);
		scanf("%d", &nxd);

		if (dist[next] - dist[now] == nwd - nxd) {
			now = next;
			nwd = nxd;
		}

		memset(visited, 0, sizeof(visited));
		dd(next, nxd, next);
		tmp.clear();
		for (int v : my) {
			if (visited[v]) {
				tmp.push_back(v);
				visited[v]++;
			}
		}
		my = tmp;
	}

	return 0;
}