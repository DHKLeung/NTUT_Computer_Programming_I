#include <stdio.h>
#include <stdbool.h>
/*Computer Programming 2016 week 11 hw 1, Coded by Leung Ho Kwan 104360098*/
void func1and2(int *ptr, int *counter) {
    int i = 0;
    for (i = 0; i < *counter; i++) {
        *(ptr + i) = 0;
    }
    *counter = 0;
}
void func3and4(int *ptr, int *counter, int element) {
    int i = 0;
    bool repeat = false;
    for (i = 0; i < *counter; i++) {
        if (*(ptr + i) == element) {
            repeat = true;
            break;
        }
    }
    if (repeat == false) {
        *(ptr + *counter) = element;
        *counter += 1;
    }
}
void func5and6(int *ptr, int *counter, int element) {
    int target = 0, i = 0;
    bool have = false;
    for (target = 0; target < *counter; target++) {
        if (*(ptr + target) == element) {
            have = true;
            break;
        }
    }
    if (have == true) {
        for (i = target; i < *counter; i++) {
            *(ptr + i) = *(ptr + i + 1);
        }
        *(ptr + *counter - 1) = 0;
        *counter -= 1;
    }
}
void func7(int a[], int b[], int acounter, int bcounter) {
    int car[40] = { 0 }, carcounter = 0, i = 0, j = 0;
    bool have = false;
    carcounter = acounter;
    for (i = 0; i < carcounter; i++) {
        car[i] = a[i];
    }
    for (i = 0; i < bcounter; i++, have = false) {
        for (j = 0; j < carcounter; j++) {
            if (b[i] == car[j]) {
                have = true;
                break;
            }
        }
        if (have == false) {
            car[carcounter] = b[i];
            carcounter++;
        }
    }
    printf("[");
    for (i = 0; i < carcounter; i++) {
        printf("%d,", car[i]);
    }
    printf("]\n");
}
void func8(int a[], int b[], int acounter, int bcounter) {
    int car[20] = { 0 }, carcounter = 0, i = 0, j = 0;
    bool have = false;
    for (i = 0; i < acounter; i++, have = false) {
        for (j = 0; j < bcounter; j++) {
            if (a[i] == b[j]) {
                car[carcounter] = a[i];
                carcounter++;
                break;
            }
        }
    }
    printf("[");
    for (i = 0; i < carcounter; i++) {
        printf("%d,", car[i]);
    }
    printf("]\n");
}
int func9(int a[], int b[], int acounter, int bcounter) {
    int i = 0, j = 0;
    bool isSubset = false;
    for (i = 0; i < acounter; i++, isSubset = false) {
        for (j = 0; j < bcounter; j++) {
            if (a[i] == b[j]) {
                isSubset = true;
                break;
            }
        }
        if (isSubset == false) {
            return 0;
        }
    }
    return 1;
}
void print1to6(int a[], int b[], int acounter, int bcounter) {
    int i = 0;
    printf("A:[");
    for (i = 0; i < acounter; i++) {
        printf("%d,", a[i]);
    }
    printf("]B:[");
    for (i = 0; i < bcounter; i++) {
        printf("%d,", b[i]);
    }
    printf("]\n");
}
int main(void) {
    int a[20] = { 0 }, b[20] = { 0 }, func, element, acounter = 0, bcounter = 0;
    while(scanf("%d", &func) && func != 0) {
        switch(func) {
            case 1:
                func1and2(a, &acounter);
                print1to6(a, b, acounter, bcounter);
                break;
            case 2:
                func1and2(b, &bcounter);
                print1to6(a, b, acounter, bcounter);
                break;
            case 3:
                scanf("%d", &element);
                func3and4(a, &acounter, element);
                print1to6(a, b, acounter, bcounter);
                break;
            case 4:
                scanf("%d", &element);
                func3and4(b, &bcounter, element);
                print1to6(a, b, acounter, bcounter);
                break;
            case 5:
                scanf("%d", &element);
                func5and6(a, &acounter, element);
                print1to6(a, b, acounter, bcounter);
                break;
            case 6:
                scanf("%d", &element);
                func5and6(b, &bcounter, element);
                print1to6(a, b, acounter, bcounter);
                break;
            case 7:
                func7(a, b, acounter, bcounter);
                break;
            case 8:
                func8(a, b, acounter, bcounter);
                break;
            case 9:
                printf("%d\n", func9(a, b, acounter, bcounter));
                break;
        }
    }
    return 0;
}
