/*
정다각형의 각의 수 n
정다각형의 내각의 합은 180*(n-2), 한 각은 180*(n-2)/n, 
세 점을 이어 표현할 수 있는 가장 작은 각은 180*(n-2)/n/(n-2) = 180/n
입력이 179인 경우를 제외한 입력에 대해 1~180범위의 g(정다각형 각 개수)를 차례로 모두 선택해본다.
선택했을 때 ang 표현 가능하면 그 g가 가장 작은 값
*/
#include <cstdio>
using namespace std;

int main() {
	int t, ang, g;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &ang);
		g = 3;
		if (ang == 179) {
			printf("360\n");
			continue;
		}
		while (g <= 180) {
			bool ss = false;
			if ((180 - 180 / g) > ang) {
				double x = 1, tmp = 180/(double)g;
				while (ang >= tmp*x) {
					if (ang == tmp*x) {
						ss = true;
						break;
					}
					x++;
				}
				if (ss) {
					printf("%d\n", g);
					break;
				}
			}
			g++;
		}
		if (g == 181)printf("%d\n", -1);
	}


	return 0;
}