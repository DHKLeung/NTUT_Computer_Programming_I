#include <stdio.h>
#include <stdbool.h>
/*Computer Programming 2016 week 9 hw 1, Coded by Leung Ho Kwan 104360098*/
void findbigprime(int k) {
    int i = 0, j = 0;
    bool isprime = true;
    for (i = k; i >= 2; i--) {
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime == true) {
            printf("%d\n", i);
            break;
        }else {
            isprime = true;
        }
    }
}
int main(void) {
    char c = ' ';
    int state = 0, deccounter = 0, x = 0, k = 0;
    while (scanf("%c", &c)) {
        if (state == 0) {
            if (c >= '2' && c <= '9') {
                x += c - 48;
                state = 1;
            }else if (c == '1' || c == '0') {
                x = c - 48;
                state = 3;
            }else if (c == '-') {
                state = 4;
            }else {
                state = -1;
                break;
            }
        }else if (state == 1) {
            if (c >= '0' && c <= '9') {
                x *= 10;
                x += c - 48;
            }else if (c == '.') {
                k = x;
                state = 2;
            }else if (c == '\n') {
                k = x;
                state = 100;
                break;
            }else {
                state = -1;
                break;
            }
        }else if (state == 2) {
            if (c >= '0' && c <= '9') {
                if (deccounter > 2) {
                    state = -1;
                    break;
                }else {
                    deccounter++;
                }
            }else if (c == '\n') {
                state = 100;
                break;
            }else {
                state = -1;
                break;
            }
        }else if (state == 3) {
            if (c >= '0' && c <= '9' && x != 0) {
                x *= 10;
                x += c - 48;
                state = 1;
            }else if (c == '\n') {
                k = 1000;
                state = 100;
                break;
            }else {
                state = -1;
                break;
            }
        }else if (state == 4) {
            if (c >= '1' && c <= '9') {
                x *= 10;
                x += c - 48;
                state = 5;
            }else {
                state = -1;
                break;
            }
        }else if (state == 5) {
            if (c >= '0' && c <= '9') {
                x *= 10;
                x += c - 48;
            }else if (c == '.') {
                x = 0;
                state = 6;
            }else if (c == '\n') {
                k = x * 11;
                state = 100;
                break;
            }else {
                state = -1;
                break;
            }
        }else if (state == 6) {
            if (c >= '0' && c <= '9') {
                if (deccounter > 2) {
                    state = -1;
                    break;
                }else {
                    x *= 10;
                    x += c - 48;
                    deccounter++;
                }
            }else if (c == '\n') {
                k = x;
                state = 100;
                break;
            }else {
                state = -1;
                break;
            }
        }
    }
    if (state == -1 || k > 1000 || k < 2) {
        printf("error\n");
    }else if (state == 100) {
        findbigprime(k);
    }
    return 0;
}
