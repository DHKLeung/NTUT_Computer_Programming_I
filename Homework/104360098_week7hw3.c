#include <stdio.h>
#include <math.h>
/*Computer Programming 2016 week 7 hw 3, Coded by Leung Ho Kwan 104360098*/
double function_1 (double point, int a) {
    return sqrt(fabs((a - pow(point, 2))));
}
double function_2 (double point, int a) {
    return fabs((((a * pow(point, 3)) + (7 * point)) / sqrt((a + point))));
}
int main(void) {
    int choice = 0, a = 0, p = 0, q = 0, err = 0, n = 2, i = 0;
    double area = 0.0, prearea = 0.0, h = 0.0;
    while (scanf("%d", &choice) && choice != 0) {
        scanf(",%d,%d,%d,%d,", &a, &p, &q, &err);
        while (1) {
            h = ((double)(q - p) / (double)n);
            if (choice == 1) {
                for (i = 0; i < n; i++) {
                    area += ((function_1((double)p + (i * h), a) + function_1((double)p + ((i + 1) * h), a)) * (h / 2));
                }
            }else if (choice == 2) {
                for (i = 0; i < n; i++) {
                    area += ((function_2((double)p + (i * h), a) + function_2((double)p + ((i + 1) * h), a)) * (h / 2));
                }
            }
            if (fabs(area - prearea) <= pow(10, 0 - err)) {
                printf("%.5lf\n", area);
                break;
            }else {
                prearea = area;
                area = 0.0;
                n++;
            }
        }
    }
    return 0;
}
