#include <stdio.h>
/*Computer Programming 2016 week 5 hw 2v2, Coded by Leung Ho Kwan 104360098*/
int main(void) {
    int a, b, c, total = 0, validcounterpre = 0, validcounternext = 0, validcounterlast = 0, i = 0;
    for (i = 0; i < 9; i++) {
        scanf("%d %d", &a, &b);
        total += a + b;
        if (a == 10 && b == 0) {
            validcounternext = 2;
            if (validcounterpre > 0) {
                total += a;
                validcounterpre--;
            }
            if (validcounterlast > 0) {
                total += a;
                validcounterlast--;
            }
        }else {
            if (a + b == 10) {
                validcounternext = 1;
            }
            if (validcounterpre == 2) {
                total += a + b;
                validcounterpre = 0;
            }else if (validcounterpre == 1) {
                total += a;
                validcounterpre = 0;
            }
            if (validcounterlast == 1) {
                total += a;
                validcounterlast = 0;
            }
        }
        validcounterlast = validcounterpre;
        validcounterpre = validcounternext;
        validcounternext = 0;
    }
    //10th round//
    scanf("%d %d %d", &a, &b, &c);
    total += a + b + c;
    if (a == 10 && b == 0) {
        if (validcounterpre == 2) {
            total += a + c;
        }else if (validcounterpre == 1) {
            total += a;
        }
        if (validcounterlast == 1) {
            total += a;
        }
    }else {
        if (validcounterpre == 2) {
            total += a + b;
        }else if (validcounterpre == 1) {
            total += a;
        }
        if (validcounterlast == 1) {
            total += a;
        }
    }
    printf("%d\n", total);
    return 0;
}