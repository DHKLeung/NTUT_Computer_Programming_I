#include <stdio.h>
/*Computer Programming 2016 week 6 hw 2, Coded by Leung Ho Kwan 104360098*/
int main(void) {	
	int row = 0;
	int i = 0, j = 0, k = 0;
	scanf("%d", &row);
	for (i = 0; i < (int)((row / 2) + 1); i++) {
		for (j = 0; j < (int)((row / 2) + 1) - i - 1; j++) {
			printf(".");
		}
		for (k = 0; k < (i * 2 + 1); k++) {
			printf("*");
		}
		for (j = 0; j < (int)((row / 2) + 1) - i- 1; j++) {
			printf(".");
		}
		printf("\n");
	}
	for (i = 0; i < (row - (int)((row / 2) + 1)); i++) {
		for (j = 0; j <= i; j++) {
			printf(".");
		}
		for (k = 0; k < row - ((i + 1) * 2); k++) {
			printf("*");
		}
		for (j = 0; j <= i; j++) {
			printf(".");
		}
		printf("\n");
	}
	return 0;
}