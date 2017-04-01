#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*Computer Programming 2016 week 10 hw 3, Coded by Leung Ho Kwan 104360098*/
int findhcf(int a, int b) {
    int i, temp;
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    for (i = a; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
}
int main(void) {
    int x1, y1, x2, y2, m1, m2, r1, r2, hcf, tempy1, carry;
    bool neg = false;
    scanf("%d/%d", &x1, &y1);
    scanf("%d/%d", &x2, &y2);
    if (x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0) {
        printf("ERROR\nERROR\n");
        return 0;
    }
    m1 = x1 * x2;
    m2 = y1 * y2;
    hcf = findhcf(abs(m1), abs(m2));
    m1 /= hcf;
    m2 /= hcf;
    tempy1 = y1;
    x1 *= y2;
    y1 *= y2;
    x2 *= tempy1;
    r1 = x1 + x2;
    r2 = y1;
    if (r1 < 0) {
        neg = true;
        r1 = abs(r1);
    }
    hcf = findhcf(r1, r2);
    r1 /= hcf;
    r2 /= hcf;
    if (r1 > r2) {
        carry = r1 / r2;
        r1 = r1 % r2;
        if (neg == true) {
            printf("-%d(%d/%d)\n", carry, r1, r2);
        }else {
            printf("%d(%d/%d)\n", carry, r1, r2);
        }
    }else {
        if (neg == true) {
            printf("-%d/%d\n", r1, r2);
        }else {
            printf("%d/%d\n", r1, r2);
        }
    }
    printf("%d/%d\n", m1, m2);
    return 0;
}
