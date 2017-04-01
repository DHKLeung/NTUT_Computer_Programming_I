#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Computer Programming 2016 week 10 hw 1, Coded by Leung Ho Kwan 104360098*/
void f1(int x1, int y1, int x2, int y2, double *m, double *b) {
    *m = (y1 - y2) / (double)(x1 - x2);
    *b = (x2*y1 - x1*y2) / (double)(x2 - x1);
}
void f2(int x1, int y1, int x2, int y2, int *m1, int *m2, int *b1, int *b2) {
    *m1 = y1 - y2;
    *m2 = x1 - x2;
    *b1 = x2*y1 - x1*y2;
    *b2 = x2 - x1;
}
int findhcf(int a, int b) {
    int i, temp;
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a == 0) {
        return 0;
    }
    for (i = a; i >= 1; i--) {
        if ((a % i == 0) && (b % i == 0)) {
            return i;
        }
    }
}
int main(void) {
    int x1, y1, x2, y2, m1, m2, b1, b2, hcfm, hcfb;
    double m, b;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    f1(x1, y1, x2, y2, &m, &b);
    f2(x1, y1, x2, y2, &m1, &m2, &b1, &b2);
    hcfm = findhcf(abs(m1), abs(m2));
    hcfb = findhcf(abs(b1), abs(b2));
    if (hcfm != 0) {
        m1 /= hcfm;
        m2 /= hcfm;
    }
    if (hcfb != 0) {
        b1 /= hcfb;
        b2 /= hcfb;
    }
    if (m == 0.0 && b == 0.0) {
        printf("y=0\n");
        printf("y=0\n");
    }else if (m == 1.0 && b == 0.0) {
        printf("y=x\n");
        printf("y=x\n");
    }else if (m == 1.0 && b != 0.0) {
        printf("y=x%c%.*lf\n", (b > 0.0)? '+' : '-', ((fabs(b) - floor(fabs(b)) > 0)? 2 : 0), fabs(b));
        if (b > 0 && b1 % b2 == 0) {
            printf("y=x+%d\n", b1 / b2);
        }else if (b > 0 && b1%b2 != 0) {
            printf("y=x+%d/%d\n", abs(b1), abs(b2));
        }else if (b < 0 && b1 % b2 == 0) {
            printf("y=x-%d\n", abs(b1) / abs(b2));
        }else if (b < 0 && b1 % b2 != 0) {
            printf("y=x-%d/%d\n",abs(b1), abs(b2));
        }
    }else if (m == 0.0 && b != 0.0) {
        printf("y=%.*lf\n", ((b - floor(b) > 0)? 2 : 0), b);
    }else if (x1 == x2) {
        printf("x=%d\n", x1);
    }else {
        printf("y=%.*lfx%c%.*lf\n", ((m - floor(m) > 0)? 2 : 0), m, (b > 0.0)? '+' : '-', ((fabs(b) - floor(fabs(b)) > 0)? 2 : 0), fabs(b));
        if (m > 0 && m1 % m2 == 0) {
            printf("y=%dx", m1 / m2);
        }else if (m > 0 && m1 % m2 != 0) {
            printf("y=%d/%dx", abs(m1), abs(m2));
        }else if (m < 0 && m1 % m2 == 0) {
            printf("y=-%d", abs(m1) / abs(m2));
        }else if (m < 0 && m1 % m2 != 0) {
            printf("y=-%d/%d", abs(m1), abs(m2));
        }
        if (b > 0 && b1 % b2 == 0) {
            printf("+%d\n", b1 / b2);
        }else if (b > 0 && b1%b2 != 0) {
            printf("+%d/%d\n", abs(b1), abs(b2));
        }else if (b < 0 && b1 % b2 == 0) {
            printf("-%d\n", abs(b1) / abs(b2));
        }else if (b < 0 && b1 % b2 != 0) {
            printf("-%d/%d\n",abs(b1), abs(b2));
        }
    }
    return 0;
}
