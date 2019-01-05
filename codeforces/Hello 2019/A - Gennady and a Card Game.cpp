#include <cstdio>
using namespace std;

int main() {
	char t[3], my[3];
	bool can = false;
	scanf("%s", t);
	for (int i = 0; i < 5; i++) {
		scanf("%s", my);
		if (my[0] == t[0]) can = true;
		if (my[1] == t[1])can = true;
	}
	if (can) printf("YES");
	else printf("NO");

	return 0;
}