/*
2 이하의 수를 제외하고 1이 답이다.
3이상의 수들은 v-1이 v의 약수가 되지 못한다.
*/
#include <cstdio>
using namespace std;

int main() {
	int v;
	scanf("%d", &v);
	if (v <= 2) printf("%d", v);
	else printf("1");

	return 0;
}