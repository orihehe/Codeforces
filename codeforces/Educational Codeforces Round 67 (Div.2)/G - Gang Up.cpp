/*
먼저 각 정점을 시간별로 분리한다.
x명 있다면 dx^2는 dx가 x번 더해지는 형태와 같다.
따라서 (<정점번호, 시간>꼴) <a,t> - <b,t+1>로의 간선을 용량이 1인 간선 50개를 추가하는데,
cost를 1d, 3d, 5d,  ... 꼴로 하여 그 간선을 이용하는 인원에 따라 cost합이 dx^2이 되도록 한다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
const int S = 12552, E = 12553;
struct mcmf {
	struct edge {
		int v, c, op, cost;
	};
	vector<edge> eg[E + 1];
	int dist[E + 1], p[E + 1], pidx[E + 1];
	bool inq[E + 1];
	void init() {
		for (int i = 0; i <= E; i++) eg[i].clear();
	}
	void addEdge(int a, int b, int f, int cost) {
		eg[a].push_back({ b,f,(int)eg[b].size(),cost });
		eg[b].push_back({ a,0,(int)eg[a].size() - 1,-cost });
	}
	bool spfa() {
		queue<int> q;
		fill(dist, dist + E + 1, INF);
		memset(inq, false, sizeof(inq));
		memset(p, -1, sizeof(p));
		dist[S] = 0;
		inq[S] = true;
		q.push(S);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			inq[cur] = false;
			int sz = eg[cur].size();
			for (int k = 0; k < sz; k++) {
				edge i = eg[cur][k];
				if (i.c > 0 && dist[cur] + i.cost < dist[i.v]) {
					dist[i.v] = dist[cur] + i.cost;
					p[i.v] = cur;
					pidx[i.v] = k;
					if (!inq[i.v]) {
						inq[i.v] = true;
						q.push(i.v);
					}
				}
			}
		}
		return p[E] != -1;
	}
	pii getAns() {
		pii ret = { 0,0 };
		while (spfa()) {
			int mn = INF;
			for (int i = E; i != S; i = p[i]) {
				mn = min(mn, eg[p[i]][pidx[i]].c);
			}
			ret.first += mn;
			for (int i = E; i != S; i = p[i]) {
				ret.second += mn * eg[p[i]][pidx[i]].cost;
				eg[p[i]][pidx[i]].c -= mn;
				eg[i][eg[p[i]][pidx[i]].op].c += mn;
			}
		}
		return ret;
	}
} mf;
int arr[51];
int main() {
	int n, m, k, c, d, last, x, t = 251, a, b;
	scanf("%d %d %d %d %d", &n, &m, &k, &c, &d);
	for (int i = 0; i < k; i++) {
		scanf("%d", &x);
		x--;
		arr[x]++;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i]) mf.addEdge(S, i*t, arr[i], 0);
		for (int j = 0; j < t - 1; j++) {
			mf.addEdge(i*t + j, i*t + j + 1, INF, i == 0 ? 0 : c);
		}
	}
	mf.addEdge(t - 1, E, k, 0);
	while (m--) {
		scanf("%d %d", &a, &b);
		a--, b--;
		for (int j = 0; j < t - 1; j++) {
			for (int i = 1; i <= 50; i++) {
				mf.addEdge(a*t + j, b*t + j + 1, 1, c + d * (i*2-1));
				mf.addEdge(b*t + j, a*t + j + 1, 1, c + d * (i * 2 - 1));
			}
		}
	}
	printf("%d", mf.getAns().second);

	return 0;
}