#include <stdio.h>
/*Computer Programming 2016 week 3 hw 3, Coded by Leung Ho Kwan 104360098*/
int main(void) {
	struct course {
		int code;
		int hr;
		char x1, y1;
		char x2, y2;
	};
	struct course st, nd, rd;
	int check = 1;
	//input first course//
	scanf("%d%d", &st.code, &st.hr);
	getchar();
	if (st.hr != 1) {
		scanf("%c%c", &st.x1, &st.y1);
		getchar();
		scanf("%c%c", &st.x2, &st.y2);
		getchar();
	}
	else {
		scanf("%c%c", &st.x1, &st.y1);
		getchar();
		st.x2 = '*';
		st.y2 = '*';
	}
	//input second course//
	scanf("%d%d", &nd.code, &nd.hr);
	getchar();
	if (nd.hr != 1) {
		scanf("%c%c", &nd.x1, &nd.y1);
		getchar();
		scanf("%c%c", &nd.x2, &nd.y2);
		getchar();
	}
	else {
		scanf("%c%c", &nd.x1, &nd.y1);
		getchar();
		nd.x2 = '-';
		nd.y2 = '-';
	}
	//input third course//
	scanf("%d%d", &rd.code, &rd.hr);
	getchar();
	if (rd.hr != 1) {
		scanf("%c%c", &rd.x1, &rd.y1);
		getchar();
		scanf("%c%c", &rd.x2, &rd.y2);
		getchar();
	}
	else {
		scanf("%c%c", &rd.x1, &rd.y1);
		getchar();
		rd.x2 = '+';
		rd.y2 = '+';
	}
	//check//
	if (st.hr > 2 || st.hr < 1 || nd.hr > 2 || nd.hr < 1 || rd.hr > 2 || rd.hr < 1) {
		check = 0;
	}
	else if ((st.hr == 2) && (st.x1 < 49 || st.x1 > 53 || st.y1 < 49 || st.y1 > 57 || st.x2 < 49 || st.x2 > 53 || st.y2 < 49 || st.y2 > 57)) {
		check = 0;
	}
	else if ((st.hr == 1) && (st.x1 < 49 || st.x1 > 53 || st.y1 < 49 || st.y1 > 57)) {
		check = 0;
	}
	else if ((nd.hr == 2) && (nd.x1 < 49 || nd.x1 > 53 || nd.y1 < 49 || nd.y1 > 57 || nd.x2 < 49 || nd.x2 > 53 || nd.y2 < 49 || nd.y2 > 57)) {
		check = 0;
	}
	else if ((nd.hr == 1) && (nd.x1 < 49 || nd.x1 > 53 || nd.y1 < 49 || nd.y1 > 57)) {
		check = 0;
	}
	else if ((rd.hr == 2) && (rd.x1 < 49 || rd.x1 > 53 || rd.y1 < 49 || rd.y1 > 57 || rd.x2 < 49 || rd.x2 > 53 || rd.y2 < 49 || rd.y2 > 57)) {
		check = 0;
	}
	else if ((rd.hr == 1) && (rd.x1 < 49 || rd.x1 > 53 || rd.y1 < 49 || rd.y1 > 57)) {
		check = 0;
	}
	//process//
	if (check == 1) {
		if ((st.x1 == nd.x1) && (st.y1 == nd.y1)) {
			printf("%d,%d,%c%c\n", st.code, nd.code, st.x1, st.y1);
			check = 0;
		}
		if ((st.x1 == nd.x2) && (st.y1 == nd.y2)) {
			printf("%d,%d,%c%c\n", st.code, nd.code, st.x1, st.y1);
			check = 0;
		}
		if ((st.x2 == nd.x2) && (st.y2 == nd.y2)) {
			printf("%d,%d,%c%c\n", st.code, nd.code, st.x2, st.y2);
			check = 0;
		}
		if ((st.x2 == nd.x1) && (st.y2 == nd.y1)) {
			printf("%d,%d,%c%c\n", st.code, nd.code, st.x2, st.y2);
			check = 0;
		}
		if ((st.x1 == rd.x1) && (st.y1 == rd.y1)) {
			printf("%d,%d,%c%c\n", st.code, rd.code, st.x1, st.y1);
			check = 0;
		}
		if ((st.x1 == rd.x2) && (st.y1 == rd.y2)) {
			printf("%d,%d,%c%c\n", st.code, rd.code, st.x1, st.y1);
			check = 0;
		}
		if ((st.x2 == rd.x2) && (st.y2 == rd.y2)) {
			printf("%d,%d,%c%c\n", st.code, rd.code, st.x2, st.y2);
			check = 0;
		}
		if ((st.x2 == rd.x1) && (st.y2 == rd.y1)) {
			printf("%d,%d,%c%c\n", st.code, rd.code, st.x2, st.y2);
			check = 0;
		}
		if ((nd.x1 == rd.x1) && (nd.y1 == rd.y1)) {
			printf("%d,%d,%c%c\n", nd.code, rd.code, nd.x1, nd.y1);
			check = 0;
		}
		if ((nd.x1 == rd.x2) && (nd.y1 == rd.y2)) {
			printf("%d,%d,%c%c\n", nd.code, rd.code, nd.x1, nd.y1);
			check = 0;
		}
		if ((nd.x2 == rd.x2) && (nd.y2 == rd.y2)) {
			printf("%d,%d,%c%c\n", nd.code, rd.code, nd.x2, nd.y2);
			check = 0;
		}
		if ((nd.x2 == rd.x1) && (nd.y2 == rd.y1)) {
			printf("%d,%d,%c%c\n", nd.code, rd.code, nd.x2, nd.y2);
			check = 0;
		}
		if (check == 1) {
			printf("correct\n");
		}
	}
	else if (check == 0) {
		printf("-1\n");
	}
	return 0;
}