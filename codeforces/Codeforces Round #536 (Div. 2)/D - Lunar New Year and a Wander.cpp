/*
왔던 길을 되돌아올 수 있으므로 
갈 수 있는 정점을 pq에 넣어 작은 값을 먼저 출력하고 봐준다.
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> vec[100001];
bool visited[100001];
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	pq.push(1);
	visited[1] = true;
	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		printf("%d ", cur);
		for (int v : vec[cur]) {
			if (!visited[v]) {
				pq.push(v);
				visited[v] = true;
			}
		}
	}

	return 0;
}