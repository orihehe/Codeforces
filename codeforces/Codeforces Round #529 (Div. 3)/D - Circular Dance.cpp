/*
i번 다음에 오는 두 사람이 입력으로 주어진다. 차례대로 주어지진 않는다.
i0번의 배열에 i1사람이 있다면 i0이 다음사람이다.
*/
#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec[200001];
bool visited[200001];
void dfs(int cur) {
	printf("%d ", cur);
	visited[cur] = true;
	int tmp = vec[cur][0];
	if (!visited[tmp] &&
		(vec[tmp][0] == vec[cur][1] || vec[tmp][1] == vec[cur][1])) {
		dfs(tmp);
	}
	else if (!visited[vec[cur][1]]) {
		dfs(vec[cur][1]);
	}
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		vec[i].push_back(a);
		vec[i].push_back(b);
	}
	dfs(1);

	return 0;
}