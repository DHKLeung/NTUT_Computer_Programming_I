#include <stdio.h>
#include <math.h>
/*Computer Programming 2016 week 1 hw 3, Coded by Leung Ho Kwan 104360098*/
int main(void) {
	double num1 = 0.0, num2 = 0.0;
	scanf("%lf%lf", &num1, &num2);
	printf("Sum:%.2f\nDifference:%.2f\nProduct:%.2f\nQuotinet:%.2f\n", num1 + num2, fabs(num1 - num2), num1 * num2, num1 / num2);
	return 0;
}
