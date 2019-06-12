/*
0이 안 나오게 하려면 1 2 1 4 1 2 1 이런 꼴이 최대를 만들 수 있다.
x또한 나오지 않도록 해야하니 x가 2^n보다 작다면 켜진 비트 하나를 제외하고 같은 꼴로 출력해준다.
*/
#include <cstdio>
#include <vector>
using namespace std;

/* 🐣🐥 */
int arr[19];
vector<int> vec;
void prt(int cur) {
	if (cur == -1) return;
	prt(cur - 1);
	printf("%d ", vec[cur]);
	prt(cur - 1);
}
int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= 18; i++) arr[i] = arr[i - 1] * 2 + 1;
	bool flag = false;
	if (x >= (1 << n)) {
		printf("%d\n", arr[n]);
		flag = true;
	}
	else printf("%d\n", arr[n - 1]);
	for (int i = 0; i < n; i++) {
		int tt = 1 << i;
		if (!flag && tt & x) flag = true;
		else vec.push_back(tt);
	}
	prt(vec.size() - 1);

	return 0;
}