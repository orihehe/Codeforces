/*
���ٰ����� ���� �� n
���ٰ����� ������ ���� 180*(n-2), �� ���� 180*(n-2)/n, 
�� ���� �̾� ǥ���� �� �ִ� ���� ���� ���� 180*(n-2)/n/(n-2) = 180/n
�Է��� 179�� ��츦 ������ �Է¿� ���� 1~180������ g(���ٰ��� �� ����)�� ���ʷ� ��� �����غ���.
�������� �� ang ǥ�� �����ϸ� �� g�� ���� ���� ��
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