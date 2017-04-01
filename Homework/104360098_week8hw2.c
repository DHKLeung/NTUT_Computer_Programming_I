#include <stdio.h>
#include <math.h>
#include <stdbool.h>
/*Computer Programming 2016 week 8 hw 2, Coded by Leung Ho Kwan 104360098*/
int promote(double cost, double have, int amount) {
    int promotion = 0;
    while (amount > 0) {
        if (have >= fabs(cost)) {
            have += cost + 1.5 + 1.5;
            amount--;
            promotion++;
        }else {
            have += 1.5;
            amount--;
        }
    }
    return promotion;
}
int main(void) {
    double cost = 0.0, have = 0.0, temp = 0.0, dotcres = 0.1;
    char c;
    int incres = 1, amount = 0;
    bool check = true, previousneg = false, previousdot = false, decone = false;
    while (scanf("%c", &c) && c != ' ') {
        if (c == '-' && previousneg == false && previousdot == false && decone == false) {
            previousneg = true;
        }else if (c >= 48 && c <= 57 && previousneg == true && previousdot == false && decone == false) {
            cost *= incres;
            cost += (double)(c - 48);
            incres *= 10;
        }else if (c == '.' && previousneg == true && previousdot == false && decone == false) {
            previousdot = true;
        }else if (c >= 48 && c <= 57 && previousneg == true && previousdot == true && decone == false) {
            temp = ((double)(c - 48)) * dotcres;
            cost += temp;
            decone = true;
        }else {
            check = false;
        }
    }
    cost = 0.0 - cost;
    previousdot = false;
    decone = false;
    incres = 1;
    while (scanf("%c", &c) && c != ' ') {
        if (c >= 48 && c <= 57 && decone == false && previousdot == false) {
            have *= incres;
            have += (double)(c - 48);
            incres *= 10;
        }else if (c == '.' && previousdot == false && decone == false) {
            previousdot = true;
        }else if (c >= 48 && c <= 57 && previousdot == true && decone == false) {
            temp = ((double)(c - 48)) * dotcres;
            have += temp;
            decone = true;
        }else {
            check = false;
        }
    }
    incres = 1;
    while (scanf("%c", &c) && c != '\n') {
        if (c >= 48 && c <= 57) {
            amount *= incres;
            amount += c - 48;
            incres *= 10;
        }else {
            check = false;
        }
    }
    if (check == false) {
        printf("Error\n");
    }else {
        printf("%d\n", promote(cost, have, amount));
    }
    return 0;
}
