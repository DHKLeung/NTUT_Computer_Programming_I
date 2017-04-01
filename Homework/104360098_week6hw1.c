#include <stdio.h>
/*Computer Programming 2016 week 6 hw 1, Coded by Leung Ho Kwan 104360098*/
int main(void) {
	int func = 0, row = 0;
	int i = 0, j = 0, k = 0;
	scanf("%d%d", &func, &row);
	if (func == 1) {
		for (i = 0; i < (int)((row / 2) + 1); i++) {
			for (j = 0; j <= i; j++) {
				printf("%d", j + 1);
			}
			printf("\n");
		}
		for (i = 0; i < row - ((int)((row / 2) + 1)); i++) {
			for (j = 0; j < (row - ((int)((row / 2) + 1))) - i; j++) {
				printf("%d", j + 1);
			}
			printf("\n");
		}
	}
	else if (func == 2) {
		for (i = 0; i < (int)((row / 2) + 1); i++) {
			for (j = 0; j < (int)((row / 2) + 1) - i - 1; j++) {
				printf(".");
			}
			for (k = i; k >= 0; k--) {
				printf("%d", k + 1);
			}
			printf("\n");
		}
		for (i = 0; i < row - ((int)((row / 2) + 1)); i++) {
			for (j = 0; j <= i; j++) {
				printf(".");
			}
			for (k = (row - ((int)((row / 2) + 1))) - i - 1; k >= 0; k--) {
				printf("%d", k + 1);
			}
			printf("\n");
		}
	}
	return 0;
}