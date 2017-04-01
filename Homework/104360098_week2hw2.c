#include <stdio.h>
#include <math.h>
/*Computer Programming 2016 week 2 hw 2, Code by Leung Ho Kwan 104360098*/
int main(void) {
	int input[5] = { 0 }, i = 0;
	float average = 0.0, diff = 0.0, stddev = 0.0;
	for (i = 0; i < 5; i++) {
		scanf("%d", &input[i]);
		average += input[i];
	}
	average /= 5.0;
	for (i = 0; i < 5; i++) {
		diff += pow((input[i] - average), 2);
	}
	diff /= 5.0;
	stddev = pow(diff, 0.5);
	printf("%.2f\n%.2f\n%.2f\n", average, diff, stddev);
	return 0;
}