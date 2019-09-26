/*
좌표 3개를 입력 받고 x좌표에 대해 오름차순 정렬을 했다.
정렬 후 차례로 a,b,c라고 하면 ax를 bx로 옮기고 ay를 by로 옮긴다.
ay를 by로 옮기는 과정 중 C의 y좌표와 가장 가까운 y좌표를 저장해둔다. (gy)
그리고 나서 gx(bx), gy에서 gx->cx로 옮긴 후 gy->cy로 옮기면 최솟값이 된다.
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define P pair<int,int>
using namespace std;

P ans[1000001];
int main() {
	P loc[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &loc[i].first, &loc[i].second);
	}
	sort(loc, loc + 3);
	int x = loc[0].first, y = loc[0].second,
		nx = loc[1].first, ny = loc[1].second;
	ans[0] = { x,y };
	int ap = 1;
	while (x != nx) {
		if (x < nx)
			++x;
		ans[ap++] = { x,y };
	}
	int cha = abs(y - loc[2].second);
	int gx = x, gy = y;
	while (y != ny) {
		if (y < ny)
			++y;
		else --y;
		if (cha > abs(y - loc[2].second)) {
			gy = y; cha = abs(y - loc[2].second);
		}
		ans[ap++] = { x,y };
	}
	nx = loc[2].first; ny = loc[2].second;
	while (gx != nx) {
		if (gx < nx)
			++gx;
		ans[ap++] = { gx,gy };
	}
	while (gy != ny) {
		if (gy < ny)
			++gy;
		else --gy;
		ans[ap++] = { gx,gy };
	}
	printf("%d\n", ap);
	for (int i = 0; i < ap; i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}