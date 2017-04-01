#include <stdio.h>
#include <stdbool.h>
/*Computer Programming 2016 week 8 hw 1, Coded by Leung Ho Kwan 104360098*/
int fibon(int need) {
    int i = 0, now = 1, previous = 1, temp = 0;
    if (need == 1 || need == 2) {
        return 1;
    }else {
        for (i = 3; i <= need; i++) {
            temp = previous;
            previous = now;
            now += temp;
        }
        return now ;
    }
}
int main(void) {
    int need = 0, pos = 1;
    char input = ' ';
    bool check = true, previousneg = false, previousnum = false;
    while(true) {
        while (scanf("%c", &input) && input != '\n') {
            if (input == '-' && previousneg == false && previousnum == false) {
                previousneg = true;
            }else if (input == '1' && previousneg == true) {
                return 0;
            }else if (input >= 48 && input <= 57 && previousneg == false) {
                need *= pos;
                need += input - 48;
                previousnum = true;
            }else {
                check = false;
            }
            pos *= 10;
        }
        if (check == false) {
            printf("Error\n");

        }else {
            printf("%d\n", fibon(need));
        }
        check = true;
        previousneg = false;
        previousnum = false;
        pos = 1;
        need = 0;
    }
    return 0;
}
