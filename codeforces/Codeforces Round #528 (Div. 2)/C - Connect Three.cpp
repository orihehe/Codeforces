/*
��ǥ 3���� �Է� �ް� x��ǥ�� ���� �������� ������ �ߴ�.
���� �� ���ʷ� a,b,c��� �ϸ� ax�� bx�� �ű�� ay�� by�� �ű��.
ay�� by�� �ű�� ���� �� C�� y��ǥ�� ���� ����� y��ǥ�� �����صд�. (gy)
�׸��� ���� gx(bx), gy���� gx->cx�� �ű� �� gy->cy�� �ű�� �ּڰ��� �ȴ�.
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