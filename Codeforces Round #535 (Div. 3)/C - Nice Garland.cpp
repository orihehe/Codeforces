/*
가능한 모든 경우를 만들어 바꿀 횟수가 가장 작은 것을 출력해준다.
R1=RBG, R2=RGB, G1=GRB, G2=GBR, B1=BGR, B2=BRG로 n만큼 반복되는 문자열을 만든다.
다음으로 st와 비교하여 다른 문자열이 있다면 각 r1,r2...변수에 카운트
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, r1, r2, g1, g2, b1, b2;
char st[200001];
char R1[200001], G1[200001], B1[200001];
char R2[200001], G2[200001], B2[200001];
int main() {
	scanf("%d", &n);
	scanf("%s", st);
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0) {
			R1[i] = R2[i] = 'R';
			B1[i] = B2[i] = 'B';
			G1[i] = G2[i] = 'G';
		}
		else if (i % 3 == 1) {
			R1[i] = G2[i] = 'B';
			B2[i] = G1[i] = 'R';
			B1[i] = R2[i] = 'G';
		}
		else if (i % 3 == 2) {
			R2[i] = G1[i] = 'B';
			B1[i] = G2[i] = 'R';
			B2[i] = R1[i] = 'G';
		}
	}
	for (int i = 0; i < n; i++) {
		if (R1[i] != st[i]) r1++;
		if (R2[i] != st[i]) r2++;
		if (B1[i] != st[i]) b1++;
		if (B2[i] != st[i]) b2++;
		if (G1[i] != st[i]) g1++;
		if (G2[i] != st[i]) g2++;
	}
	int minV = min({ r1,r2,b1,b2,g1,g2 });
	printf("%d\n", minV);
	if (minV == r1) printf("%s", R1);
	else if (minV == r2) printf("%s", R2);
	else if (minV == b1) printf("%s", B1);
	else if (minV == b2) printf("%s", B2);
	else if (minV == g1) printf("%s", G1);
	else if (minV == g2) printf("%s", G2);

	return 0;
}