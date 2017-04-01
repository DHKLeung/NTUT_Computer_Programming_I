#include <stdio.h>
#include <math.h>
/*Computer Programming 2016 week 1 hw 2, Coded by Leung Ho Kwan 104360098*/
int main(void) {
	int a = 0, b = 0, c = 0;
	scanf("%d%d%d", &a, &b, &c);
	printf("%.1f\n%.1f", (float)(((-b) + sqrt(b*b - 4 * a*c)) / (2 * a)), (float)(((-b) - sqrt(b*b - 4 * a*c)) / (2 * a)));
	return 0;
}
