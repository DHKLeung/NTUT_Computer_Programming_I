#include <stdio.h>
/*Computer Programming 2016 week 2 hw 1, Coded by Leung Ho Kwan 104360098*/
int getTriangle(int a, int b, int c) {
	if ((a > 0) && (b > 0) && (c > 0) && ((a + b) > c) && ((a + c) > b) && ((c + b) > a)) {
		if ((a == b) && (a == c)) {
			return 2;
		}
		else if ((a == b) || (a == c)) {
			return 3;
		}
		else {
			return 4;
		}
	}
	else {
		return 1;
	}
}
int main(void) {
	int x = 0, y = 0, z = 0;
	scanf("%d%d%d", &x, &y, &z);
	printf("%d\n", getTriangle(x, y, z));
	return 0;
}
