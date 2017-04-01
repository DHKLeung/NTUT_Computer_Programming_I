#include <stdio.h>
#include <math.h>
/*Computer Programming 2016 week 2 hw 3, Code by Leung Ho Kwan 104360098*/
int main(void) {
	int a = 0, b = 0, c = 0, cons = 0;
	double t = 0.0, x1 = 0.0, x2 = 0.0, x11 = 0.0, x12 = 0, x21 = 0.0, x22 = 0.0;
	scanf("%d%d%d", &a, &b, &c);
	cons = b * b - 4 * a * c;
	if (cons >= 0) {
		t = sqrt(cons);
		x1 = (float)(-b + t) / (float)(2 * a);
		x2 = (float)(-b - t) / (float)(2 * a);
		printf("%.1f\n%.1f\n", x1, x2);
	}
	else {
		x11 = (float)(-b) / (float)(2 * a);
		x21 = (float)(-b) / (float)(2 * a);
		t = sqrt(fabs(cons));
		x12 = (float)t / (float)(2 * a);
		x22 = (float)t / (float)(2 * a);
		printf("%.1f+%.1fi\n", x11, x12);
		printf("%.1f-%.1fi\n", x21, x22);
	}
	return 0;
}