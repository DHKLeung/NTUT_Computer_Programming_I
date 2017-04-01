#include <stdio.h>
#include <math.h>
/*Computer Programming 2016 week 7 hw 1, Coded by Leung Ho Kwan 104360098*/
int main(void) {
	int input = 0, b = 0, counter = 1, output = 0, i = 0, tempinput = 0;
	scanf("%d %d", &b, &input);
	if (!((b <= 9) && (b >= 2) && (input >= 0) && (input <= 10000000))) {
		printf("-1\n");
	}
	else {
		tempinput = input;
		while (tempinput >= b) {
			tempinput /= b;
			counter++;
		}
		while (i < counter) {
			output += round((pow(10, i) * (input % b)));
			input /= b;
			i++;
		}
		printf("%d\n", output);
	}
	return 0;
}
