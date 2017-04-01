#include <stdio.h>
#include <math.h>
/*Computer Programming 2016 week 7 hw 2, Coded by Leung Ho Kwan 104360098*/
double function_1(int n, int c, int d, double x) {
   return (pow(x, n) - (c * pow(x, n - 2)) - d);
}
double function_1_dev(int n, int c, double x) {
    return ((n * pow(x, n - 1)) - ((n - 2) * c * pow(x, n - 3)));
}
double function_2(int n, int c, int d, double x) {
    return (pow(x, n) - (c * x) - d);
}
double function_2_dev(int n, int c, double x) {
    return ((n * pow(x, n - 1)) - c);
}
int main(void) {
    int choice = 0, n = 0, c = 0, d = 0, err = 0;
    double x = 0.0, prex = 0.0;
    scanf("%d %d %d %d %d", &choice, &n, &c, &d, &err);
    prex = ((double)d / 2);
    if (choice == 1) {
        while (1) {
            x = prex - (function_1(n, c, d, prex) / function_1_dev(n, c, prex));
            if (fabs(x - prex) <= pow(10, 0 - err)) {
                printf("%.*lf\n", err + 1, floor(x * pow(10, err + 1)) / pow(10, err + 1));
                break;
            }else {
                prex = x;
            }
        }
    }else if (choice == 2) {
        while (1) {
            x = prex - (function_2(n, c, d, prex) / function_2_dev(n, c, prex));
            if (fabs(x - prex) <= pow(10, 0 - err)) {
                printf("%.*lf\n", err + 1, floor(x * pow(10, err + 1)) / pow(10, err + 1));
                break;
            }else {
                prex = x;
            }
        }
    }
    return 0;
}
