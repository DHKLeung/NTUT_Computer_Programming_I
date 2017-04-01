#include <stdio.h>
/*Computer Programming 2016 week 3 hw 2, Coded by Leung Ho Kwan 104360098*/
int compute(int a, int b, int c) {
	if (!((a + b > c) && (a + c > b) && (b + c > a))) {
		return 0;
	}
	else if (((a * a + b * b) == c * c) || ((a * a + c * c) == b * b) || ((b * b + c * c) == a * a)) {
		return 1;
	}
	else if ((((a * a + b * b) > c * c) + ((a * a + c * c) > b * b) + ((b * b + c * c) > a * a)) == 3){
		return 3;
	}
	else if (((a * a + b * b) < c * c) || ((a * a + c * c) < b * b) || ((b * b + c * c) < a * a)) {
		return 2;
	}
}
int main(void) {
	int a = 0, b = 0, c = 0, result = 0;
	scanf("%d%d%d", &a, &b, &c);
	result = compute(a, b, c);
	printf("%s\n", ((result == 1) ? "Right Triangle" : ((result == 2) ? "Obtuse Triangle" : ((result == 3) ? "Acute Triangle" : "Not Triangle"))));
	return 0;
}