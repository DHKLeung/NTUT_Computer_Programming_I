#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*Computer Programming 2016 week 12 hw 1, Coded by Leung Ho Kwan 104360098*/
void input(char input1[], char input2[], int *length1, int *length2) {
    scanf("%s", input1);
    scanf("%s", input2);
    *length1 = strlen(input1);
    *length2 = strlen(input2);
}
void allzero(int array[]) {
    int i = 0;
    for (i = 0; i < 480; i++) {
        array[i] = 0;
    }
}
void print(int array[], int dotplace, int dotlimit) {
    int i, counter = 0;
    bool front = false, dotstart = false;
    for (i = 479; i >= 0; i--) {
        if (front == false && dotstart == false && array[i] == 0) {
            continue;
        }else if (front == false && dotstart == false && array[i] != 0) {
            printf("%d", array[i]);
            front = true;
        }else if (front == true && dotstart == false) {
            printf("%d", array[i]);
        }else if (front == true && dotstart == true) {
            printf("%d", array[i]);
            counter += 1;
            if (counter == dotlimit) {
                break;
            }
        }
        if (i == dotplace) {
            printf(".");
            dotstart = true;
        }
    }
    if (front == false) {
        printf("0");
    }
    printf("\n");
}
bool oneissmaller(char cinput1[], char cinput2[], int length1, int length2) {
    int i;
    if (length1 < length2) {
        return true;
    }else if (length1 == length2) {
        for (i = length1 - 1; i >= 0; i--) {
            if (cinput1[i] < cinput2[i]) {
                return true;
            }else if (cinput1[i] > cinput2[i]) {
                return false;
            }else if (cinput1[i] == cinput2[i]) {
                continue;
            }
        }
        return false;
    }else {
        return false;
    }
}
void normalize(char cinput1[], char cinput2[], int *length1, int *length2) {
    char temp[241];
    int templength;
    if (oneissmaller(cinput1, cinput2, *length1, *length2)) {
        strcpy(temp, cinput1);
        strcpy(cinput1, cinput2);
        strcpy(cinput2, temp);
        templength = *length1;
        *length1 = *length2;
        *length2 = templength;
    }
}
void addarray(char cinput1[], char cinput2[], int length1, int length2, int result[]) {
    int i, carry = 0, sum;
    for (i = 0; i < length2; i++) {
        sum = cinput1[i] - 48 + cinput2[i] - 48 + carry;
        result[i] = sum % 10;
        if (sum > 9) {
            carry = 1;
        }else {
            carry = 0;
        }
    }
    for (;i < length1; i++) {
        sum = cinput1[i] - 48 + carry;
        result[i] = sum % 10;
        if (sum > 9) {
            carry = 1;
        }else {
            carry = 0;
        }
    }
    if (carry == 1) {
        result[i] = 1;
    }
}
void addition(char input1[], char input2[], int length1, int length2, int result[], int dotplace, int dotlimit) {
    char cinput1[241], cinput2[241];
    strcpy(cinput1, input1);
    strcpy(cinput2, input2);
    strrev(cinput1);
    strrev(cinput2);
    normalize(cinput1, cinput2, &length1, &length2);
    addarray(cinput1, cinput2, length1, length2, result);
    print(result, dotplace, dotlimit);
    allzero(result);
}
void minusarray(char cinput1[], char cinput2[], int length1, int length2, int result[]) {
    int i, carry = 0, sum;
    for (i = 0; i < length2; i++) {
        sum = (cinput1[i] - 48) - (cinput2[i] - 48) - carry;
        if (sum < 0) {
            carry = 1;
            result[i] = sum + 10;
        }else {
            carry = 0;
            result[i] = sum;
        }
    }
    for (; i < length1; i++) {
        sum = cinput1[i] - 48 - carry;
        if (sum < 0) {
            carry = 1;
            result[i] = sum + 10;
        }else {
            carry = 0;
            result[i] = sum;
        }
    }
}
void deduction(char input1[], char input2[], int length1, int length2, int result[], int dotplace, int dotlimit) {
    char cinput1[241], cinput2[241];
    strcpy(cinput1, input1);
    strcpy(cinput2, input2);
    strrev(cinput1);
    strrev(cinput2);
    if (oneissmaller(cinput1, cinput2, length1, length2)) {
        printf("-");
    }
    normalize(cinput1, cinput2, &length1, &length2);
    minusarray(cinput1, cinput2, length1, length2, result);
    print(result, dotplace, dotlimit);
    allzero(result);
}
void accu(int temppro[], int result[]) {
    int i, carry = 0, sum;
    for (i = 0; i < 480; i++) {
        sum = result[i] + temppro[i] + carry;
        carry = (sum - sum % 10) / 10;
        sum = sum % 10;
        result[i] = sum;
    }
}
void multiarray(char cinput1[], char cinput2[], int length1, int length2, int result[]) {
    int temppro[480] = { 0 }, i, j, sum, carry = 0;
    for (i = 0; i < length2; i++) {
        for (j = 0; j < length1; j++) {
            sum = (cinput2[i] - 48) * (cinput1[j] - 48) + carry;
            carry = (sum - sum % 10) / 10;
            sum = sum % 10;
            temppro[i + j] = sum;
        }
        temppro[i + j] = carry;
        accu(temppro, result);
        allzero(temppro);
        carry = 0;
    }
}
void multiply(char input1[], char input2[], int length1, int length2, int result[], int dotplace, int dotlimit) {
    char cinput1[241], cinput2[241];
    strcpy(cinput1, input1);
    strcpy(cinput2, input2);
    strrev(cinput1);
    strrev(cinput2);
    normalize(cinput1, cinput2, &length1, &length2);
    multiarray(cinput1, cinput2, length1, length2, result);
    print(result, dotplace * 2, dotlimit);
    allzero(result);
}
int finddpplace(char array[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (array[i] == '.') {
            return length - i - 1;
        }
    }
}
void eliminatedot(char array[], int length, int dotplace) {
    int i;
    for (i = dotplace; i < length; i++) {
        array[i] = array[i + 1];
    }
}
void dpprocess(char input1[], char input2[], int *length1, int *length2, int *dp1, int *dp2) {
    int dpd, i;
    *dp1 = finddpplace(input1, *length1);
    *dp2 = finddpplace(input2, *length2);
    dpd = abs(*dp1 - *dp2);
    if (*dp1 < *dp2) {
        for (i = 0; i < dpd; i++) {
            strcat(input1, "0");
        }
        *length1 = *length1 + dpd;
        *dp1 = *dp1 + dpd;
    }else {
        for (i = 0; i < dpd; i++) {
            strcat(input2, "0");
        }
        *length2 = *length2 + dpd;
        *dp2 = *dp2 + dpd;
    }
    eliminatedot(input1, *length1, *length1 - 1 - *dp1);
    eliminatedot(input2, *length2, *length2 - 1 - *dp2);
    *length1 = *length1 - 1;
    *length2 = *length2 - 1;
}
int main(void) {
    char input1[241], input2[241];
    int result[480] = { 0 }, length1, length2, dp1, dp2, dotlimit, dotplace;
    input(input1, input2, &length1, &length2);
    scanf("%d", &dotlimit);
    dpprocess(input1, input2, &length1, &length2, &dp1, &dp2);
    dotplace = dp1;
    addition(input1, input2, length1, length2, result, dotplace, dotlimit);
    deduction(input1, input2, length1, length2, result, dotplace, dotlimit);
    multiply(input1, input2, length1, length2, result, dotplace, dotlimit);
    return 0;
}
