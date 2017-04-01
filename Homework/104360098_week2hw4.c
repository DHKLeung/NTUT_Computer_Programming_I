#include <stdio.h>
#include <math.h>
/*Computer Programming 2016 week 2 hw 4, Code by Leung Ho Kwan 104360098*/
int main(void) {
	int x = 0, y = 0, z = 0;
	scanf("%d%d%d", &x, &y, &z);
	if (x >= 1 && x <= 10) {
		x = round((float)380 * x);
	}
	else if (x >= 11 && x <= 20) {
		x = round((float)380 * 0.9 * x);
	}
	else if (x >= 21 && x <= 30) {
		x = round((float)380 * 0.85 * x);
	}
	else if (x >= 31) {
		x = round((float)380 * 0.8 * x);
	}
	else {
		x = 0;
	}
	if (y >= 1 && y <= 10) {
		y = round((float)1200 * y);
	}
	else if (y >= 11 && y <= 20) {
		y = round((float)1200 * 0.95 * y);
	}
	else if (y >= 21 && y <= 30) {
		y = round((float)1200 * 0.85 * y);
	}
	else if (y >= 31) {
		y = round((float)1200 * 0.8 * y);
	}
	else {
		y = 0;
	}
	if (z >= 1 && z <= 10) {
		z = round((float)180 * z);
	}
	else if (z >= 11 && z <= 20) {
		z = round((float)180 * 0.85 * z);
	}
	else if (z >= 21 && z <= 30) {
		z = round((float)180 * 0.8 * z);
	}
	else if (z >= 31) {
		z = round((float)180 * 0.7 * z);
	}
	else {
		z = 0;
	}
	printf("%d\n", x + y + z);
	return 0;
}