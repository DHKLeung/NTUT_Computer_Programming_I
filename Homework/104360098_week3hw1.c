#include <stdio.h>
#include <math.h>
/*Computer Programming 2016 week 3 hw 1, Coded by Leung Ho Kwan 104360098*/
int main(void) {
	int inner = 0, outer = 0, cit = 0, inmes = 0, outmes = 0;
	int t183 = 0, t383 = 0, t983 = 0;
	scanf("%d%d%d%d%d", &inner, &outer, &cit, &inmes, &outmes);
	t183 = round(((inner * 0.08) + (outer * 0.139) + (cit * 0.135) + (inmes * 1.128) + (outmes * 1.483)));
	t383 = round(((inner * 0.07) + (outer * 0.130) + (cit * 0.121) + (inmes * 1.128) + (outmes * 1.483)));
	t983 = round(((inner * 0.06) + (outer * 0.108) + (cit * 0.101) + (inmes * 1.128) + (outmes * 1.483)));
	if (t183 <= 183) {
		t183 = 183;
	}
	if (t383 <= 383) {
		t383 = 383;
	}
	if (t983 <= 983) {
		t983 = 983;
	}
	if ((t183 < t383) && (t183 < t983)) {
		printf("183\n%d\n", t183);
	}
	else if ((t383 < t183) && (t383 < t983)) {
		printf("383\n%d\n", t383);
	}
	else {
		printf("983\n%d\n", t983);
	}
	return 0;
}