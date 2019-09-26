/*
세로 블럭은 1,1 - 2,1 와 3,1 - 4,1
가로 블럭은 4,3 - 4,4 와 4,1 - 4,2 자리에 놓는다.
세로의 1,1 가로의 4,3 에 각각 먼저 놓고, 다음 블럭에 따라 각 줄을 없앤다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool b[5][5];
bool r[4], c[4];
int main() {
	string st;
	cin >> st;
	int len = st.size();
	int hn = 0, vn = 0;
	int x, y;
	for (int i = 0; i < len; i++) {
		if (st[i] == '0') {
			if (b[1][1]) {
				b[1][1] = false;
				x = 3, y = 1;
			}
			else {
				b[1][1] = true;
				x = 1, y = 1;
			}
		}
		else if (st[i] == '1') {
			if (b[4][3]) {
				b[4][3] = false;
				x = 4, y = 1;
			}
			else {
				b[4][3] = true;
				x = 4, y = 3;
			}
		}
		printf("%d %d\n", x, y);
	}

	return 0;
}