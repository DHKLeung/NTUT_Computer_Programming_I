#include <stdio.h>
/*Computer Programming 2016 week 1 hw 1, Coded by Leung Ho Kwan 104360098*/
int main(void) {
	char name = ' ';
	int s_id = 0, st = 0, nd = 0, rd = 0;
	scanf("%c", &name);
	scanf("%d%d%d%d", &s_id, &st, &nd, &rd);
	printf("Name:%c\nId:%d\nTotal:%d\nAverage:%d", name, s_id, st + nd + rd, (st + nd + rd) / 3);
	return 0;
}
