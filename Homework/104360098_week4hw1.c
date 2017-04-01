#include <stdio.h>
#include <stdlib.h>
/*Computer Programming 2016 week 4 hw 1, Coded by Leung Ho Kwan 104360098*/
int main(void) {
	int input[6];
	int smallest = 0, largest = 0;
	int i;
	for (i = 0; i < 6; i++) {
		scanf("%d", &input[i]);
		if (smallest > input[i]) {
			smallest = input[i];
		}
		if (largest < input[i]) {
			largest = input[i];
		}
	}
	int adjust = 0;
	if (smallest < adjust) {
		adjust = adjust - smallest;
		for (i = 0; i < 6; i++) {
			input[i] = input[i] + adjust;
		}
	}
	else {
		adjust = smallest - adjust;
		for (i = 0; i < 6; i++) {
			input[i] = input[i] - adjust;
		}
	}
	int *dir = malloc(sizeof(int) * (largest - smallest + 1));
	for (i = 0; i < (largest - smallest + 1); i++) {
		*(dir + i) = 0;
	}
	for (i = input[0]; i <= input[1]; i++) {
		if (*(dir + i) != 1) {
			*(dir + i) = 1;
		}
	}
	for (i = input[2]; i <= input[3]; i++) {
		if (*(dir + i) != 1) {
			*(dir + i) = 1;
		}
	}
	for (i = input[4]; i <= input[5]; i++) {
		if (*(dir + i) != 1) {
			*(dir + i) = 1;
		}
	}
	int start = 0;
	int length = 0;
	for (i = 0; i < (largest - smallest + 1); i++) {
		if ((*(dir + i) == 1) && start == 0) {
			start = 1;
			length += 1;
		}
		else if ((*(dir + i) == 1) && start == 1) {
			if (i != (largest - smallest + 1) - 1) {
				length += 1;
			}
		}
		else if ((*(dir + i) == 0) && start == 1) {
			start = 0;
			length -= 1;
		}
		else if ((*(dir + i) == 0) && start == 1) {
			start = 0;
			length -= 1;
		}
	}
	free(dir);
	printf("%d\n", length);
	return 0;
}