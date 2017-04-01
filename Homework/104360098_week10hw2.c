#include <stdio.h>
#include <stdlib.h>
/*Computer Programming 2016 week 10 hw 2, Coded by Leung Ho Kwan 104360098*/
void compute(int x1, int y1, int x2, int y2, int *perimeter, int *area) {
    int length, height;
    length = abs(x1 - x2);
    height = abs(y1 - y2);
    *perimeter = (length + height) * 2;
    *area = length * height;
}
int main(void) {
    int x1, y1, x2, y2, firmarea = 0, area, perimeter, firmperi = 0;
    while (scanf("%d", &x1) && x1 != -1) {
        scanf("%d %d %d", &y1, &x2, &y2);
        compute(x1, y1, x2, y2, &perimeter, &area);
        if (area > firmarea) {
            firmarea = area;
        }
        if (perimeter > firmperi) {
            firmperi = perimeter;
        }
    }
    printf("%d\n%d\n", firmarea, firmperi);
    return 0;
}
