#include <stdio.h>
/*Computer Programming 2016 week 4 hw 1v2, Coded by Leung Ho Kwan 104360098*/
int checkoverlap(int x11, int x12, int x21, int x22) {
	int overlap = 0;
	if (x11 < x21) {
		if ((x12 > x21) && (x12 <= x22)) {
			overlap = x12 - x21;
		}
		else if (x12 > x22) {
			overlap = x22 - x21;
		}
	}
	else {
		if ((x22 > x11) && (x22 <= x12)) {
			overlap = x22 - x11;
		}
		else if (x22 > x12) {
			overlap = x12 - x11;
		}
	}
	return overlap;
}
int main(void) {
	int ax1, ax2, bx1, bx2, cx1, cx2;
	scanf("%d%d%d%d%d%d", &ax1, &ax2, &bx1, &bx2, &cx1, &cx2);
	printf("%d\n", (ax2 - ax1) + (bx2 - bx1) + (cx2 - cx1) - checkoverlap(ax1, ax2, bx1, bx2) - checkoverlap(ax1, ax2, cx1, cx2) - checkoverlap(bx1, bx2, cx1, cx2));
	return 0;
}