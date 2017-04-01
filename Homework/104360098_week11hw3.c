#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*Computer Programming 2016 week 11 hw 3, Coded by Leung Ho Kwan 104360098*/
void input(char *sign, char *iinput1, char *input2);
void coeandpower(int *coe, char *input, int *tempcoe, int *temppower, int xpos);
void splitcoe(int *coe, char *input);
int eachhighestpower(int *coe);
void addpoly(int *coe1, int *coe2, int *result, int coe1high, int coe2high);
void minuspoly(int *coe1, int *coe2, int *result, int coe1high, int coe2high);
void timespoly(int *coe1, int *coe2, int *result, int coe1high, int coe2high, int highestpower);
void printresult(int *result, int high);
int main(void) {
    char input1[51], input2[51], sign;
    int coe1[20] = { 0 }, coe2[20] = { 0 }, result[40] = { 0 }, coe1high, coe2high, timeshighestpower, highestpower, i;
    input(&sign, input1, input2);
    splitcoe(coe1, input1);
    splitcoe(coe2, input2);
    coe1high = eachhighestpower(coe1);
    coe2high = eachhighestpower(coe2);
    timeshighestpower = coe2high + coe1high;
    highestpower = (coe2high > coe1high) ? coe2high : coe1high;
    if (sign == '+') {
        addpoly(coe1, coe2, result, coe1high, coe2high);
        printresult(result, highestpower);
    }else if (sign == '-') {
        minuspoly(coe1, coe2, result, coe1high, coe2high);
        printresult(result, highestpower);
    }else if (sign == '*') {
        timespoly(coe1, coe2, result, coe1high, coe2high, timeshighestpower);
        printresult(result, timeshighestpower);
    }
    return 0;
}
void input(char *sign, char *input1, char *input2) {
    scanf("%c", sign);
    getchar();
    scanf("%[^\n]s", input1);
    getchar();
    scanf("%[^\n]s", input2);
    getchar();
}
void coeandpower(int *coe, char *input, int *tempcoe, int *temppower, int xpos) {
    int i, times = 1;
    for (i = xpos - 1; i >= 0; i--) {
        if (i == 0 && input[i] != '-') {    //get the highest power's coe if positive
            *tempcoe = (input[i] - 48) * times;
            break;
        }else if (i == 0 && input[i] == '-') {  //get the highest power's coe if negative
            if (xpos == 1) {
                *tempcoe = -1;
            }else {
                *tempcoe = 0 - *tempcoe;
            }
            break;
        }else if (input[i] == ' ') {    //get the coe = 1 if no coe is at the front of x
            if (*tempcoe == 0) {
                *tempcoe = 1;
            }
            if (input[i - 1] == '-') {  //make the coe become negative if negative
                *tempcoe = 0 - *tempcoe;
                break;
            }else {
                break;
            }
        }else { //accumulate the coe
            *tempcoe = (input[i] - 48) * times;
        }
        times *= 10;
    }
    if (xpos == 0) {
        *tempcoe = 1;
    }
    if (input[xpos + 1] == '^') {   //get the power if the power != 1
        *temppower = input[xpos + 2] - 48;
    }else { //power = 1
        *temppower = 1;
    }
}
void splitcoe(int *coe, char *input) {
    int i, j, temp, tempcoe = 0, temppower = 0;
    bool ispos, nox = true;
    for (i = 0; i < 31; i++) {
        if (input[i] == '\0') { //get the last coe of x^0, insert to array
            for (temp = i; temp >= 0; temp--) {
                if (input[temp] == 'x') {
                    break;
                }
            }
            for (j = temp + 1; j < i; j++) {
                if (input[j] == ' ') {
                    if (input[j + 1] == '+') {
                        ispos = true;
                    }else if (input[j + 1] == '-') {
                        ispos = false;
                    }
                    j += 3;
                    break;
                }
            }
            tempcoe = 0;
            temppower = 0;
            for (; j < i; j++) {
                tempcoe *= 10;
                tempcoe += input[j] - 48;
            }
            if (ispos == false) {
                tempcoe = 0 - tempcoe;
            }
            coe[temppower] = tempcoe;
            break;
        }else if (input[i] == 'x') {    //return coe and power, insert to array
            nox = false;
            tempcoe = 0;
            temppower = 0;
            coeandpower(coe, input, &tempcoe, &temppower, i);
            coe[temppower] = tempcoe;
        }
    }
    ispos = true;
    if (nox == true) {  //if only integers
        for (i = 0; i < strlen(input); i++) {
            if (input[i] == '-') {
                ispos = false;
            }else {
                tempcoe *= 10;
                tempcoe += input[i] - 48;
            }
        }
        if (ispos == false) {
            tempcoe = 0 - tempcoe;
        }
        coe[0] = tempcoe;
    }
}
int eachhighestpower(int *coe) {
    int i;
    for (i = 19; i >= 0; i--) {
        if (coe[i] != 0) {
            return i;
        }
    }
    return 0;
}
void addpoly(int *coe1, int *coe2, int *result, int coe1high, int coe2high) {
    int i;
    for (i = 0; i < 20; i++) {
        result[i] = coe1[i] + coe2[i];
    }
}
void minuspoly(int *coe1, int *coe2, int *result, int coe1high, int coe2high) {
    int i;
    for (i = 0; i < 20; i++) {
        result[i] = coe1[i] - coe2[i];
    }
}
void timespoly(int *coe1, int *coe2, int *result, int coe1high, int coe2high, int highestpower) {
    int i, j, workingpower, temp = 0;
    for (workingpower = highestpower; workingpower >= 0; workingpower--) {
        for (i = coe1high; i >= 0; i--) {
            for (j = coe2high; j >= 0; j--) {
                if (i + j == workingpower) {
                    temp += coe1[i] * coe2[j];
                }
            }
        }
        result[workingpower] = temp;
        temp = 0;
    }
}
void printresult(int *result, int high) {
    int i;
    bool front = false, allzero = true;
    for (i = high; i >= 0; i--) {   //find the actual highest power
        if (result[i] != 0) {
            allzero = false;
            high = i;
            break;
        }
    }
    if (allzero == true) {  //if allzero then print '0'
        printf("0\n");
        return;
    }else {
        for (i = high; i >= 0; i--) {
            if (front != true && result[i] != 1 && result[i] != -1) {   //print coe
                printf("%d", result[i]);
                front = true;
            }else if (front != true && result[i] == -1) {
                printf("-");
                front = true;
            }else if (front != true && result[i] == 1) {
                front = true;
            }else if (front == true && result[i] == 0) {
                continue;
            }else if (front == true && i != 0 && result[i] > 1) {
                printf(" + %d", result[i]);
            }else if (front == true && i != 0 && result[i] < -1) {
                printf(" - %d", abs(result[i]));
            }else if (front == true && i != 0 && result[i] == 1) {
                printf(" + ");
            }else if (front == true && i != 0 && result[i] == -1) {
                printf(" - ");
            }else if (front == true && i == 0 && result[i] > 0) {
                printf(" + %d", result[i]);
            }else if (front == true && i == 0 && result[i] < 0) {
                printf(" - %d", abs(result[i]));
            }
            if (i > 1) {
                printf("x^%d", i);
            }else if (i == 1) {
                printf("x");
            }
        }
        printf("\n");
    }
}
